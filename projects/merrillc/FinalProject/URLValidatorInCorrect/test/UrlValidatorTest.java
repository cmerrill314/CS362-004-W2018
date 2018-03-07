import junit.framework.TestCase;
//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {
	private boolean printStatus = false;
	private boolean printIndex = false;

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   //--------------------------------------------------------------------------------------------------------------------------
   // Manual Test Cases
   //
   // Concept:
   // We are dealing with a combination of scheme, authority, port, path and query. So the idea is to test the cases where all
   // are known to be valid, and then change one component at a time to be invalid to see if we get a failing result.
   //--------------------------------------------------------------------------------------------------------------------------
   public void testManualTest() {
	   System.out.println("MANUAL TEST RESULTS:");
	   System.out.println("--------------------");
	   
	   //Create a new UrlValidator
	   UrlValidator url = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //TEST 1: VALID: Scheme, Authority and Port
	   System.out.println("Expected: true  | Actual: " + url.isValid("http://www.github.com"));
	   //Riam/Jesus - add more URL's for this test here if you want!
	   
	   //TEST 2: VALID: Scheme, Authority, Port and Path
	   System.out.println("Expected: true  | Actual: " + url.isValid("http://www.github.com/pulls"));
	   //Riam/Jesus - add more URL's for this test here if you want!
	   
	   //TEST 3: VALID: Scheme, Authority, Port, Path and Query
	   System.out.println("Expected: true  | Actual: " + url.isValid("http://github.com/search?utf8=%E2%9C%93&q=chris&type="));
	   //Riam/Jesus - add more URL's for this test here if you want!
	   
	   //TEST 4: VALID: Authority and Port. INVALID: Scheme 
	   System.out.println("Expected: false | Actual: " + url.isValid("htt://www.github.com"));
	   //Riam/Jesus - add more URL's for this test here if you want!
	   
	   //TEST 5: VALID: Scheme and Port. INVALID: Authority
	   System.out.println("Expected: false | Actual: " + url.isValid("256.256.256.256"));
	   //Riam/Jesus - add more URL's for this test here if you want!
	   
	   //TEST 6: VALID: Scheme and Authority. INVALID: Port
	   System.out.println("Expected: false | Actual: " + url.isValid("255.255.255.255:-1"));
	   //Riam/Jesus - add more URL's for this test here if you want!
	   
	   //TEST 7: VALID: Scheme, Authority and Port. INVALID: Path
	   System.out.println("Expected: false | Actual: " + url.isValid("https://github.com/aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
	   //Riam/Jesus - add more URL's for this test here if you want!
   }
   
   public void testFirstPartition() {
	//You can use this function to implement your First Partition testing	   
   }
   
   public void testSecondPartition() {
	//You can use this function to implement your Second Partition testing	   
   }
   
    //You can create more test cases for your Partitions if you need to 
   
   public void testIsValid() {
	//You can use this function for programming based testing
   } 
}
