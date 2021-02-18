/ Activity 1.3 (part 2): store 150 data and add all of them.

storeData,  Input / Ask for input
            StoreI LOC / Store indirectly input value in LOC

            Load LOC / Load LOC in AC
            Add ONE / Add ONE to AC
            Store LOC / Store AC in LOC

            Load NUM / Load NUM in AC
            Add ONE / Add ONE to AC
            Store NUM / Store AC in NUM

            Load TIMES / Load TIMES in AC
            Subt ONE / Substract ONE to AC
            Store TIMES / Store AC in TIMES
            
            Skipcond 400 / Skip if AC is equal to 0
            Jump storeData / Jump to "add" subroutine

add,  Load RES / Load RES in AC
      AddI BASE / Add indirectly value of the address LOC to AC
      Store RES / Store AC in RES
      
      Load BASE / Load BASE in AC
      Add ONE / Add ONE to AC
      Store BASE / Store AC in BASE

      Load NUM / Load NUM in AC
      Subt ONE / Substract ONE to AC
      Store NUM / Store AC in NUM
            
      Skipcond 400 / Skip if AC is equal to 0
      Jump add / Jump to "add" subroutine

Load RES
Output
Halt

ONE, DEC 1
NUM, DEC 0 / In this case, NUM represents the new "TIMES"
BASE, HEX 30
RES, DEC 0
LOC, HEX 30 / Location
TIMES, DEC 150
