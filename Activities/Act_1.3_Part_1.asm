/ Activity 1.3 (part 1): store 150 data using StoreI

storeData,  Input / Ask for input
            StoreI LOC / Store indirectly input value in LOC

            Load LOC / Load LOC in AC
            Add ONE / Add ONE to AC
            Store LOC / Store AC in LOC

            Load TIMES / Load TIMES in AC
            Subt ONE / Substract ONE to AC
            Store TIMES / Store AC in TIMES

            Skipcond 400 / Skip if AC is equal to 0
            Jump storeData / Jump to "add" subroutine

Output
Halt

ONE, DEC 1
NUM, DEC 0
LOC, HEX 30 / Location
TIMES, DEC 150
