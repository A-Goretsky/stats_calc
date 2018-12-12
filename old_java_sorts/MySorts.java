//Anton Goretsky
//APCS1 pd5
//HW51 -- Dat Bubbly Tho
//2015-12-21

import java.util.ArrayList;

public class MySorts {

    //~~~~~~~~~~~~~~~~~~~ HELPER METHODS ~~~~~~~~~~~~~~~~~~~
    //precond: lo < hi && size > 0
    //postcond: returns an ArrayList of random integers
    //          from lo to hi, inclusive
    public static ArrayList populate( int size, int lo, int hi ) 
    {
	ArrayList<Integer> retAL = new ArrayList<Integer>();
	while( size > 0 ) {
	    //     offset + rand int on interval [lo,hi]
	    retAL.add( lo + (int)( (hi-lo+1) * Math.random() ) );
	    size--;
	}
	return retAL;
    }


    //randomly rearrange elements of an ArrayList
    public static void shuffle( ArrayList al ) 
    {
	int randomIndex;
	//setup for traversal fr right to left
        for( int i = al.size()-1; i > 0; i-- ) {
	    //pick an index at random
            randomIndex = (int)( (i+1) * Math.random() );
	    //swap the values at position i and randomIndex
            al.set( i, al.set( randomIndex, al.get(i) ) );
        }
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //BUBBLE SORT METHODS

    // VOID version of bubbleSort
    // Rearranges elements of input ArrayList
    // postcondition: data's elements sorted in ascending order
	//MY COMMENTS - Sorts through array list from back to front, swapping
	//when necessary and as many times as the size - 1 of the input is.
    public static void bubbleSortV( ArrayList<Comparable> data ) {
        for (int y = 0; y < data.size() - 1; y++) {
            for (int x = data.size() - 2; x >= 0; x--) {
                if (data.get(x).compareTo(data.get(x + 1)) > 0) {
                    data.set(x + 1, data.set(x, data.get(x + 1)));
                }
            }
        }
    }//end bubbleSortV -- O(n^2)


    // ArrayList-returning bubbleSort
    // postcondition: order of input ArrayList's elements unchanged
    //                Returns sorted copy of input ArrayList.
	//MY COMMENTS - Makes a copy
    public static ArrayList<Comparable> bubbleSort( ArrayList<Comparable> input ) {
		ArrayList<Comparable> ans = new ArrayList<Comparable>();
		for (Comparable x : input) {
			ans.add(x);
		}
        bubbleSortV(ans);
		return ans;
    }//end bubbleSort -- O(n^2)
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //SELECTION SORT METHODS
    
    public static int min(ArrayList<Comparable> data, int ctr) {
		int index = ctr;
        for (int x = ctr + 1; x < data.size(); x++) {
			if (data.get(index).compareTo(data.get(x)) > 0) {
				index = x;
			}
		}
		return index;
	}
	
    // VOID version of SelectionSort
    // Rearranges elements of input ArrayList
    // postcondition: data's elements sorted in ascending order
    public static void selectionSortV( ArrayList<Comparable> data ) {
		int ctr = 0;
		for (int x = 0; x < data.size(); x++) {
			int minInd = min(data, ctr);
			data.set(x, (data.set(minInd, data.get(x))));
			ctr++;
		}
    }//end selectionSort -- O(n^2)


    // ArrayList-returning selectionSort
    // postcondition: order of input ArrayList's elements unchanged
    //                Returns sorted copy of input ArrayList.
    public static ArrayList<Comparable> selectionSort( ArrayList<Comparable> input ) {
        ArrayList<Comparable> ans = new ArrayList<Comparable>();
		for (Comparable x : input) {
			ans.add(x);
		}
		selectionSortV(ans);
		return ans;
    }//end selectionSort -- O(n^2)*/
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //BOGO SORT METHODS
    
    public static boolean isSorted(ArrayList<Comparable> data){
        for (int i = 1; i < data.size(); i++) {
           if (data.get(i).compareTo(data.get(i-1)) < 0)
               return false;
        }
        return true;
    }
    
    public static void bogoSortV(ArrayList<Comparable> data) {
        while (!isSorted(data)) {
            shuffle(data);
        }
    }
    
    public static ArrayList<Comparable> bogoSort(ArrayList<Comparable> data) {
        ArrayList<Comparable> ans = new ArrayList<Comparable>();
        for (Comparable x : data) {
            ans.add(x);
        }
        bogoSortV(ans);
        return ans;
    }
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //INSERTION SORT METHODS
    
    //VOID METHOD
    public static void insertionSortV( ArrayList<Comparable> data ) {
        for (int x = 1; x < data.size(); x++) {
            int ctr = x - 1;
            while ((ctr >= 0) && (data.get(ctr + 1).compareTo(data.get(ctr)) < 0)) {
                data.set(ctr, data.set(ctr + 1, data.get(ctr)));
                ctr--;
            }
        }
    }
    
    //AL-RETURNING METHOD
    public static ArrayList<Comparable> insertionSort( ArrayList<Comparable> input ) {
        ArrayList<Comparable> ans = new ArrayList<Comparable>();
        for (Comparable x : input) {
            ans.add(x);
        }
        insertionSortV(ans);
        return ans;
    }
}
