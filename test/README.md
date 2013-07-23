test_cell
===============

# How to use test_cell

Read sources. test_cell.h, test_cell.c

sample main.c

```
#include"test_cell.h"
int main ( int argc , char** argv ) {
  int proc;
  int i;
  double a[5], b[5];

  MPI_Init( &argc, &argv );
  MPI_Comm_rank( MPI_COMM_WORLD, &proc );

  /* init test */
  testInit( argv , proc );

  for (i = 0; i < 5; i++)
    b[i] = i;
  a[0] = b[0];
  a[1] = b[1];
  a[2] = b[2];
  a[3] = b[3];
  a[4] = b[4];
  for (i = 0; i < 5; i++)
    testCell( "test_a", a[i], 0.1 );
}
```

compile

```
$ gcc main.c test_cell.c -lm
```

make test file & save testCell's second arg

```
$ ./a.out -w
```

refactoring main.c

```
#include"test_cell.h"
int main ( int argc , char** argv ) {
  int proc;
  int i;
  double a[5], b[5];

  MPI_Init( &argc, &argv );
  MPI_Comm_rank( MPI_COMM_WORLD, &proc );

  /* init test */
  testInit( argv , proc );

  for (i = 0; i < 5; i++) {
    b[i] = i;
    a[i] = b[i];
    testCell( "test_a", a[i], 0.1 );
  }
}
```

compile refactored main.c

```
$ gcc main.c test_cell.c -lm
```

test it

```
$ ./a.out -t
```

success

```
test_a success
test_a success
test_a success
test_a success
test_a success
```

wrong refactoring main.c

```
#include"test_cell.h"
int main ( int argc , char** argv ) {
  int proc;
  int i;
  double a[5], b[5];

  MPI_Init( &argc, &argv );
  MPI_Comm_rank( MPI_COMM_WORLD, &proc );

  /* init test */
  testInit( argv , proc );

  for (i = 0; i < 5; i++) {
    b[i] = i;
    a[i] = b[0]; /* WRONG */
    testCell( "test_a", a[i], 0.1 );
  }
}
```

compile it

```
$ gcc main.c test_cell.c -lm
```

test it

```
$ ./a.out -t
```

fail

```
test_a success
test_a fail | input=0.000000 : file=1.000000
test_a fail | input=0.000000 : file=2.000000
test_a fail | input=0.000000 : file=3.000000
test_a fail | input=0.000000 : file=4.000000
```

