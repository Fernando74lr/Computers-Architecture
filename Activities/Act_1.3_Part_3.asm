/ Activity 1.3 (part 3): find max and min of all the stored data.
/ Bug: if the list isn't sorted from lower to higher, it fails giving the min.
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

      Load NUM / Load NUM in AC
      Subt ONE / Substract ONE to AC
      Store NUM / Store AC in NUM
            
      Skipcond 400 / Skip if AC is equal to 0
      Jump add / Jump to "add" subroutine

/ Leave BASE 1 POSITION BEHIND THE BEGINNING
Load BASE
Subt ONE
Store BASE

/ Locate LOC in the last position of the input stored list
Load LOC
Subt ONE
Store LOC

LoadI LOC
StoreI BASE

Jump max_and_min

check_min, Load Z
		   Skipcond 000 / skip if AC < 0
           Jump check_end

           Load ALPHA
           Subt MIN
           Store TMP / tmp = alpha - min
           
           Skipcond 800 / skip if AC > 0
           Jump check_end
           
           Load ALPHA
           Store MIN / max = alpha
           
           Jump check_end

check_max, Load Z
		   Skipcond 800 / skip if AC > 0
           Jump check_min
           
           Load ALPHA
           Subt MAX
           Store TMP / tmp = alpha - max
           
           Skipcond 800 / skip if AC > 0
           Jump check_end
           
           Load ALPHA
           Store MAX / max = alpha
           
           Jump check_end

check_end, Load LOC
		   Subt BASE
           Skipcond 400 / skip if AC == 0
           Jump max_and_min
           Jump end_program

max_and_min, LoadI LOC
			 Store ALPHA / alpha = (loc)I
             
             Load LOC
             Subt ONE
             Store LOC / loc = loc - 1
             
             LoadI LOC
             Store PHI / phi = (loc - 1)I
             
             Load ALPHA
             Subt PHI
             Store Z / z = alpha - phi
             
             Skipcond 400 / skip if AC == 0
             Jump check_max
             Jump check_end            
             
end_program, Load RES
			 Output
             Load MAX
             Output
             Load MIN
             Output
			 Halt

ONE, DEC 1
NUM, DEC 0 / In this case, NUM represents the new "TIMES"
BASE, HEX 100
RES, DEC 0
LOC, HEX 100 / Location
TIMES, DEC 150 / 150

Z, DEC 0
MAX, DEC 0
MIN, DEC 0
TMP, DEC 0
ALPHA, DEC 0
PHI, DEC 0
