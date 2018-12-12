/*
  Janet Zhang
  APCS2 pd5
  HW09 -- Mergers and Acquisitions. . .
  2016-03-05
*/

/*======================================
  class MergeSort
  Implements mergesort on array of ints.

  Summary of Algorithm: 
  when merge is called, it makes sure a and b are sorted lists,
  it makes counters for a, b, and a new list
  the new list is populated by comparing a and b where their counters are
  then after one counter reaches the length of its list, 
  the rest of the next list is added to the end of the new list
    
  When sort is called, it takes the array, splits it in half,
  and then it calls merge on it. 
  When the array in sort is of length1 or less, it is returned.
  When merge is called, it puts the arrays in order and returns it to sort
    
  ======================================*/

public class MergeSort {

    /******************************************************
     * int[] merge(int[],int[]) 
     * Merges two input arrays
     * Precond:  Input arrays are sorted in ascending order
     * Postcond: Input arrays unchanged, and 
     * output array sorted in ascending order.
     ******************************************************/
    private static int[] merge( int[] a, int[] b ) {
        //new array
        int[] janet=new int[a.length+b.length];
        //make sure inputs are sorted
        int[] aprime = sort(a);
        int[] bprime = sort(b);
        int acounter = 0, bcounter = 0;
        //for each element of janet
        for (int jcounter = 0; jcounter < janet.length; jcounter++) {
            //handles if sizes aren't the same and stuff is left over,
            //everything left is jsut added to the rest of janet
            if (acounter >= aprime.length) {
                janet[jcounter] = bprime[bcounter];
                bcounter++;
            } 
            else if (bcounter >= bprime.length) {
                janet[jcounter] = aprime[acounter];
                acounter++;
            } 
            //if find the smaller one, then set element of janet to smaller 
            else if (aprime[acounter] < bprime[bcounter]) {
                janet[jcounter] = aprime[acounter];
                acounter++;
            } 
            else {
                janet[jcounter] = bprime[bcounter];
                bcounter++;
            }
        }
        //returns the sorted list
        return janet;
    }
    

    /******************************************************
     * int[] sort(int[]) 
     * Sorts input array using mergesort algorithm
     * Returns sorted version of input array (ascending)
     ******************************************************/
    public static int[] sort( int[] arr ) {	
        //if it's length 1 it's sorted
        if (arr.length <= 1) {
            return arr;
        } 
        else {
            //split arr
            int[] arr1=new int[arr.length/2];
            int[] arr2=new int[arr.length - arr.length/2];
            for (int i = 0; i <arr.length; i++) {
                //populate arr1 and arr2 with each element of arr
                if (i < arr1.length) {
                    arr1[i] = arr[i];
                } 
                else {
                    //the index makes it restart at 0 after arr1 is complete
                    arr2[i-arr1.length] = arr[i];
                }
            }
            return merge(arr1, arr2);
        }
    }

    //-------------------HELPERS-------------------------
    //tester function for exploring how arrays are passed
    //usage: print array, mess(array), print array. Whaddayasee?
    public static void mess( int[] a ) {
	for( int i = 0 ; i<a.length; i++ )
	    a[i] = 0;
    }

    //helper method for displaying an array
    public static void printArray( int[] a ) {
	System.out.print("[");
	for( int i : a )
	    System.out.print( i + ",");
	System.out.println("]");
    }
    //---------------------------------------------------


    //main method for testing
    public static void main( String [] args ) {

	int[] arr0 = {0};
	int[] arr1 = {1};
	int[] arr2 = {1,2};
	int[] arr3 = {3,4};
	int[] arr4 = {1,2,3,4};
	int[] arr5 = {4,3,2,1};
	int[] arr6 = {9,42,17,63,0,512,23};
	int[] arr7 = {9,42,17,63,0,9,512,23,9};
	/*
	  System.out.println("\nTesting mess-with-array method...");
	  printArray( arr3 );
	  mess(arr3);
	  printArray( arr3 );
	*/

	System.out.println("\nMerging arr1 and arr0: ");
	printArray( merge(arr1,arr0) );

	  System.out.println("\nMerging arr4 and arr6: ");
	  printArray( merge(arr4,arr6) );

	  System.out.println("\nSorting arr4-7...");
	  printArray( sort( arr4 ) );
	  printArray( sort( arr5 ) );
	  printArray( sort( arr6 ) );
	  printArray( sort( arr7 ) );
	/*~~~~~~~~~~~~~~ Ye Olde Tester Bar ~~~~~~~~~~~~~~
	  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    }//end main()

}//end class MergeSort
