/ Activity 1.3 (part 3): find max and min of all the stored data.
/ NOT FINISHED YET :)
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
            Jump storeData / Jump to "storeData" subroutine

/ Go back to base HEX 30
Load BASE
Store LOC

add,  Load RES / Load RES in AC
      AddI LOC / Add indirectly value of the address LOC to AC
      Store RES / Store AC in RES
      
      Load LOC / Load LOC in AC
      Add ONE / Add ONE to AC
      Store LOC / Store AC in LOC
      
      Load TIMES / Load TIMES in AC
      Add ONE / Add ONE to AC
      Store TIMES / Store AC in TIMES
            
      Load NUM / Load NUM in AC
      Subt ONE / Substract ONE to AC
      Store NUM / Store AC in NUM
            
      Skipcond 400 / Skip if AC is equal to 0
      Jump add / Jump to "add" subroutine

/ Set LOC at the last data
Load LOC / At this point LOC is in 00C6
Subt ONE
Store LOC / At this point LOC is in 00C5

maxAndMin,    Load LOC / LOC is in 00C4
			  Subt ONE / LOC is in 00C3
              Store LOC

			  LoadI LOC / Load 149
			  Store SUBST_TMP
              
  			  Load LOC
			  Add ONE / LOC is in 00C4
              Store LOC
              
              LoadI LOC / Load 150 to AC
			  Subt SUBST_TMP / Substract 149 to 150 = 1
              Store SUBST_TMP
              
              Skipcond 800 / Skip if AC (SUBST_TMP) > 0
              Skipcond 000 / Skip if AC (SUBST_TMP) < 0
              Jump firstIf / IF 1
              Jump secondIf / IF 2

subsLOC,  Load LOC
		  Subt ONE
          Store LOC
          Jump maxAndMin

firstIf, LoadI LOC / 150
	     Subt MAX / 150 - 0 = 150
	     Store TMP / TMP = 150
      
	     Load TMP / AC = 150
	     Skipcond 800 / Skip if AC > 0 ✔
	     Output
	     LoadI LOC / AC = 150
	     Store MAX / MAX = 150
      
      	 Load ZERO
         Store TMP / TMP = 0
      	
	     Load TIMES
	     Subt ONE
	     Store TIMES
      
	     Skipcond 400 / Skip if AC == 0
	     Jump subsLOC / Return to loop
	     Jump end / End program

secondIf, LoadI LOC / 150
		  Store TMP / TMP = 150
          Load MIN / AC = 0
          Subt TMP / 0 - TMP = -150
          Store TMP / TMP = -150
      
	      Load TMP / AC = -150
	      Skipcond 800 / Skip if AC > 0 ✔
	      Output
          
      
 	      Load TIMES
	      Subt ONE
	      Store TIMES
      
	      Skipcond 400 / Skip if AC == 0
	      Jump subsLOC / Return to loop
	      Jump end / End program

end, Load RES
	 Output
	 Halt

ONE, DEC 1
NUM, DEC 0 / In this case, NUM represents the new "TIMES"
BASE, HEX 30
RES, DEC 0
LOC, HEX 30 / Location
TIMES, DEC 3 /150

ZERO, DEC 0
MAX, DEC 0
MIN, DEC 0
TMP, DEC 0
SUBST_TMP, DEC 0
