/*

Team: White_vans
Janet, Anton, Shamaul
APCS2 pd5
HW11 -- Wrapping It Up
2016-03-11

 */

/*======================================
  class MergeSortTester
  ALGORITHM:
  When one runs a sort on a certain aray, the sort method is first called.
  It checks if the array is of length one, if so, it returns, otherwise it begins
  to split the original input array, creating empty arrays half the size and
  populating them, recursing on each half, first heading down a single branch of the
  recursive "break-down" tree. Once a branch is fully split, the merging is called,
  and the arrays merge back sorted, via a comparison of the elements within, looking at
  the frontmost element, one index at a time. Once the counter exceeds the lengths of one of
  the list you are merging, it continues on with the list you have not finished, by adding it
  on to the array. (The splitting continues down the next branch of the recursive tree, followed
  by merging, and so on, until the final branch is hit, and fully merged with the previously split/sorted
  ones, and the array is sorted.)
  BIG-OH CLASSIFICATION OF ALGORITHM:
  O(n log(n))
  Our runtime classification of mergesort is: n*log(n). We think the log(n)
comes from splitting the array, and the linear runtime comes from the merging
of the arrays.

If n is the length of the array, then the depth of the binary decision tree
would be log(n) (As Aparna mentioned on her post to Piazza). Therefore,
there is a logarithmic correlation between the length of the array and the
number of steps it takes the split the array into arrays of length=1.

During the merging of the arrays, every element is “touched” once when
deciding the order of the elements in the merged list, and it is through this
action that the linear aspect of the big O is produced. Although it isn’t
exactly following a runtime of O(n), we follow the rule where classifications
similar to this run-time are “reduced” down to a general form of O(n).
  //log base 2

  Mean execution times for dataset of size n:
  Batch size: 10
  n=1       time: 3660.0 ns
  n=10      time: 21401.6 ns
  n=100     time: 177408.0 ns
  ...
  n=<huge>  time: 168.2 ms
  ANALYSIS:
  As the length of the data set grows, the time increases by a different factor each time.
  from n=1 to n=10, the time increases by a factor of ~5.
  from n=10 to n=100, the time increases by a factor of ~8.
  Since the factor is not constant, the runtime must be greater than a linear runtime. it resembles a nlog(n) graph.
  ======================================*/

public class MergeSortTester
{
    /******************************
     * execution time analysis
     * To calculate the time it takes for the function,
     * we set the beginning time as System.currentTimeMillis
     * then we find the end time by calling the same command
     * Then we find the total time it took for mergesort by
     * subtracting beginning from end time
     ******************************/
    public static void pop(int[] j, int n){
	for(int x=0;x<n;x++){j[n]=(int)(Math.random()*100);}
    }

    public static double tester(int[] arr) {
        double beginning=System.nanoTime();
    	MergeSort.sort(arr);
    	double end=System.nanoTime();
    	return end-beginning;
    }
    public static void findMean(int[] arr, int batchSize){
        double mean=0;
        for(int x = 0; x<batchSize; x++){
            mean+=tester(arr);

        }
        System.out.print("Avg time to sort length" + arr.length + ": " );
        System.out.println(mean/(batchSize));

    }
    public static void main( String[] args )
    {
	MergeSort a=new MergeSort();
	int[] batch1={1};
	int[] batch2={10,9,8,7,6,5,4,3,2,1};
	int[] batch3=new int[100];
	//pop(batch3, batch3.length-1);
	int[] batch4=new int[10000];
	//pop(batch4, batch4.length-1);
	int[] batch5=new int[1000000];
	//pop(batch5, batch5.length-1);

/*
	double beginning=System.nanoTime();
	a.sort(batch1);
	double end=System.nanoTime();
	System.out.print("Time to sort length1: " );
	System.out.println(end-beginning);

	beginning=System.nanoTime();
	a.sort(batch2);
	end=System.nanoTime();
	System.out.print("Time to sort length10: " );
	System.out.println(end-beginning);

	beginning=System.nanoTime();
	a.sort(batch3);
	end=System.nanoTime();
	System.out.print("Time to sort length100: " );
	System.out.println(end-beginning);

	beginning=System.nanoTime();
	a.sort(batch4);
	end=System.nanoTime();
	System.out.print("Time to sort length10000: " );
	System.out.println(end-beginning);

	beginning=System.currentTimeMillis();
	a.sort(batch5);
	end=System.currentTimeMillis();
	System.out.print("Time to sort length1000000: " );
	System.out.println(end-beginning);
*/

findMean(batch1,10);
findMean(batch2,10);
findMean(batch3,10);
findMean(batch5,10);

}//end main


}//end class
