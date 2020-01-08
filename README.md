# Partition-Function-recursive-C
Partition Function or Integer Partition recursive in C

Jede Integer Partitionierung wird in jeder moeglichen Reihenfolge erzeugt.

Every integer partitioning is created in every possible order.

Example:

1

    1


2

    1 1
    
    2


3

    1 1 1
    
    1 2
    
    2 1
    
    3


4

    1 1 1 1
    
    1 1 2
    
    1 2 1
    
    1 3
    
    2 1 1
    
    2 2
    
    3 1
    
    4


5

    1 1 1 1 1
    
    1 1 1 2
    
    1 1 2 1
    
    1 1 3
    
    1 2 1 1
    
    1 2 2
    
    1 3 1
    
    1 4
    
    2 1 1 1
    
    2 1 2
    
    2 2 1
    
    2 3
    
    3 1 1
    
    3 2
    
    4 1
    
    5


Der Algorithmus arbeitet folgendermassen:

The algorithm works as follows:

N ist eine natuerliche Zahl, die partitioniert werden soll.

N is a natural number to be partitioned.

X ist eine natuerliche Zahl, die von 1 bis N schrittweise um 1 erhöht wird.

X is a natural number that is incremented by 1 from 1 to N.

partitions(0) := leere Menge

partitions(0) := empty set

partitions(N) := X konkateniert mit allen partitions(N - X)

partitions(N) := X concatenates with all partitions(N - X)


Schreibe Deine eigene Funktion, die fuer jede Integer Partitionierung ausgefuehrt werden soll.

Write your own function that should be performed for each integer partitioning.

Die aktuelle Partitionierung wird als 0-terminiertes Array übergeben.

The current partitioning is passed as a 0-terminated array.

Du kannst dieses Projekt in Eclipse CDT importieren.

You can import this project into Eclipse CDT.

