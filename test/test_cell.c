#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <search.h>
#include "test_cell.h"

#define MAX_FILE_NAME_LENGTH 20
#define MAX_TEST_NAME_LENGTH 80
#define MAX_TEST_NUM 2500
#define MAX_BUF_NUM  100

FILE* fp;
void ( *fun )( char*, double, double );

char
parseOp( char** argv );
void
testArg( char* testName, double cell, double diff );
void
writeArg( char* testName, double cell, double diff );
void
skipTest( char* testName, double cell, double diff );
ENTRY*
findOrCreateHash( char* testName );
int
getCount( ENTRY* ep );
void
assertCell( char* testName, double cell, double fileCell, double diff );

void
testInit( char** argv , int proc )
{
  char op;
  char fileName[MAX_FILE_NAME_LENGTH];
  sprintf( fileName, "data/proc%d.dat", proc ) ;

  op = parseOp( argv );
  hcreate( MAX_TEST_NUM );
  switch( op ) {
    case 't':
      fp = fopen( fileName, "r" );
      fun = testArg;
      break;
    case 'w':
      mkdir( "./data", 0777 ) ;
      fp = fopen( fileName, "w" );
      fun = writeArg;
      break;
    default:
      fun = skipTest;
      break;
  }
}

void
testCell( char* testName, double cell, double diff )
{
  if( fun != NULL && cell != 0 && isnan(cell) == 0 )
    fun( testName, cell, diff );
}

void
testFinish()
{
  hdestroy();
  if( fp != NULL )
    fclose(fp);
}

void
testArg( char* testName, double cell, double diff )
{
  int    cnt = 0;
  char   buff[MAX_BUF_NUM];
  char   fileTestName[MAX_TEST_NAME_LENGTH];
  double fileCell;

  cnt = getCount( findOrCreateHash( testName ) );

  fseek( fp, 0L, SEEK_SET );
  while( fgets( buff, sizeof( buff ), fp ) != NULL ) {
    sscanf ( buff, "%lf%s\n", &fileCell, fileTestName );
    if( strcmp( fileTestName, testName ) == 0 ) {
      if( cnt > 0 ) {
        cnt--;
        continue;
      }
      assertCell( testName, cell, fileCell, diff );
      break;
    }
  }
}

void
writeArg( char* testName, double cell, double diff )
{
  fprintf( fp, "%lf%s\n", cell, testName );
}

void
skipTest( char* testName, double cell, double diff )
{
  return;
}

char
parseOp( char** argv )
{
  char op;
  while( *++argv != NULL ) {
    if( **argv == '-' )
      op = *(*argv+1);
  }
  return op;
}

ENTRY*
findOrCreateHash( char* testName )
{
  ENTRY* ep;
  ENTRY e;
  e.key = strdup( testName );
  ep = hsearch( e, FIND );
  if( ep != NULL ) {
    (int)( ep->data )++;
  } else {
    e.data = (void*)0;
    ep = hsearch( e, ENTER );
  }
  return ep;
}

int
getCount( ENTRY* ep )
{
  int cnt = 0;
  if( ep != NULL )
    cnt = (int)( ep->data );
  return cnt;
}

void
assertCell( char* testName, double cell, double fileCell, double diff )
{
  if( fabs( cell - fileCell ) <= diff ) {
    printf ( "\x1b[32m %s success\n", testName );
  } else {
    printf( "\x1b[31m %s fail | input=%lf : file=%lf\n", testName, cell, fileCell );
  }
}
