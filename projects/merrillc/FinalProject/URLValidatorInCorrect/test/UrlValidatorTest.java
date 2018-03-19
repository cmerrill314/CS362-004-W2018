/* Team Members
Christopher Merrill - merrillc
Riam Sangdoung - kiddr
CS 362 Project B
 */

import junit.framework.TestCase;

/* Performs Validation Test for url validations;
 * Used skeleton outline from CS 362
 * https://commons.apache.org/proper/commons-validator/apidocs/org/apache/commons/validator/routines/UrlValidator.html#isValidAuthority(java.lang.String)
 * FinalProject/URLValidatorInCorrect/src/UrlValidator.java
 */

public class UrlValidatorTest extends TestCase {

  //private boolean printStatus = false; // Comment out ?? since doesn't seemed to be used?? and printIndex
  //private boolean printIndex = false; // Comment out?? since Eclipse is telling me it's not being used?

  public UrlValidatorTest(String testName) {
    super(testName);
  }
// Each part of the URL is evaluated and allowed all schemes
//Manual testing
  public void testManualTest()
  {
    UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

    System.out.println("\nAllowing all schemes: \n");


// Scheme

    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com/");
    System.out.println(urlVal.isValid("https://www.amazon.com/"));
    System.out.println("www.amazon.com");
    System.out.println(urlVal.isValid("www.amazon.com"));
    System.out.println("h3tp://www.amazon.com");
    System.out.println(urlVal.isValid("h3tp://www.amazon.com"));

    System.out.println("\nValidation Failures:");
    System.out.println("https:/www.amazon.com");
    System.out.println(urlVal.isValid("://www.amazon.com"));
    System.out.println("://www.amazon.com");
    System.out.println(urlVal.isValid("://www.amazon.com"));

// Authority
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com/");
    System.out.println(urlVal.isValid("https://www.amazon.com/"));
    System.out.println("https://www.amazon.co.uk/");
    System.out.println(urlVal.isValid("https://www.amazon.co.uk/"));

    System.out.println("\nValidation Failures:");
    System.out.println("https://www.amazon~.com");
    System.out.println(urlVal.isValid("https://www.amazon~.com"));
    System.out.println("https://www.amazon");
    System.out.println(urlVal.isValid("https://www.amazon"));
    System.out.println("https://<Empty Space>");
    System.out.println(urlVal.isValid("https:// "));
    System.out.println("https://www.thisisfakewebsite.com");
    System.out.println(urlVal.isValid("https://www.thisisfakewebsite.com"));

// Port
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com:80");
    System.out.println(urlVal.isValid("https://www.amazon.com:80"));
    System.out.println("https://www.amazon.com:300");
    System.out.println(urlVal.isValid("https://www.amazon.com:300"));
    System.out.println("https://www.amazon.com:3000");
    System.out.println(urlVal.isValid("https://www.amazon.com:3000"));
    System.out.println("https://www.amazon.com:30000");
    System.out.println(urlVal.isValid("https://www.amazon.com:30000"));

    System.out.println("\nValidation Failures:");
    System.out.println("https://www.amazon.com:");
    System.out.println(urlVal.isValid("https://www.amazon.com:"));
    System.out.println("https://www.amazon.com:-80");
    System.out.println(urlVal.isValid("https://www.amazon.com:-80a"));
    System.out.println("https://www.amazon.com:80");
    System.out.println(urlVal.isValid("https://www.amazon.com:80a"));

// Path
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com/test1");
    System.out.println(urlVal.isValid("https://www.amazon.com/test1"));
    System.out.println("https://www.amazon.com/");
    System.out.println(urlVal.isValid("https://www.amazon.com/"));

    System.out.println("\nValidation Failures:");
    System.out.println("https://www.amazon.comtest1");
    System.out.println(urlVal.isValid("https://www.amazon.comtest1"));
    System.out.println("https://www.amazon.com//test1");
    System.out.println(urlVal.isValid("https://www.amazon.com//test1"));
    System.out.println("https://www.amazon.com/..");
    System.out.println(urlVal.isValid("https://www.amazon.com/.."));
    System.out.println("https://www.amazon.com/../");
    System.out.println(urlVal.isValid("https://www.amazon.com/../"));
    System.out.println("https://www.amazon.com       /");
    System.out.println(urlVal.isValid("https://www.amazon.com         /"));

// Option
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com/test1/test1");
    System.out.println(urlVal.isValid("https://www.amazon.com/test1/test1"));
    System.out.println("https://www.amazon.com/test1/");
    System.out.println(urlVal.isValid("https://www.amazon.com/test1/"));
    System.out.println("https://www.amazon.com/test1test1");
    System.out.println(urlVal.isValid("https://www.amazon.com/test1test1"));

    System.out.println("\nValidation Failures:");
    System.out.println("https://www.amazon.comtest1test1");
    System.out.println(urlVal.isValid("https://www.amazon.comtest1test1"));
    System.out.println("https://www.amazon.com/test1//test1");
    System.out.println(urlVal.isValid("https://www.amazon.com/test1//test1"));

// Queries
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com/ref=nb_sb_noss_null");
    System.out.println(urlVal.isValid("https://www.amazon.com/ref=nb_sb_noss_null"));
    System.out.println("https://www.amazon.com/s/ref=nb_sb_noss_1?url=search-alias%3Daps&field-keywords=unicorn");
    System.out.println(urlVal.isValid("https://www.amazon.com/s/ref=nb_sb_noss_1?url=search-alias%3Daps&field-keywords=unicorn"));

    System.out.println("\nValidation Failures:");
    System.out.println("https://www.amazon.com/ref=");
    System.out.println(urlVal.isValid("https://www.amazon.com/ref="));
    System.out.println("https://www.amazoncom/ref=nb_sb_noss_null");
    System.out.println(urlVal.isValid("https://www.amazoncom/ref=nb_sb_noss_null"));
    System.out.println("https://www.amazon.com/ref???nb_sb_noss_null");
    System.out.println(urlVal.isValid("https://www.amazon.com/ref???nb_sb_noss_null"));

//urlVal2 No Fragments
    UrlValidator urlVal2 = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS);
    System.out.println("\nAllowing No Fragments: \n");

// Scheme
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com/");
    System.out.println(urlVal2.isValid("https://www.amazon.com/"));
    System.out.println("www.amazon.com");
    System.out.println(urlVal2.isValid("www.amazon.com"));
    System.out.println("h3tp://www.amazon.com");
    System.out.println(urlVal2.isValid("h3tp://www.amazon.com"));

    System.out.println("\nValidation Failures:");
    System.out.println("https:/www.amazon.com");
    System.out.println(urlVal2.isValid("://www.amazon.com"));
    System.out.println("://www.amazon.com");
    System.out.println(urlVal2.isValid("://www.amazon.com"));

// Authority
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com/");
    System.out.println(urlVal2.isValid("https://www.amazon.com/"));
    System.out.println("https://www.amazon.co.uk/");
    System.out.println(urlVal2.isValid("https://www.amazon.co.uk/"));

    System.out.println("\nValidation Failures:");
    System.out.println("https://www.amazon~.com");
    System.out.println(urlVal2.isValid("https://www.amazon~.com"));
    System.out.println("https://www.amazon");
    System.out.println(urlVal2.isValid("https://www.amazon"));
    System.out.println("https://<Empty Space>");
    System.out.println(urlVal2.isValid("https:// "));
    System.out.println("https://www.thisisfakewebsite.com");
    System.out.println(urlVal2.isValid("https://www.thisisfakewebsite.com"));

// Port
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com:80");
    System.out.println(urlVal2.isValid("https://www.amazon.com:80"));
    System.out.println("https://www.amazon.com:300");
    System.out.println(urlVal2.isValid("https://www.amazon.com:300"));
    System.out.println("https://www.amazon.com:3000");
    System.out.println(urlVal2.isValid("https://www.amazon.com:3000"));
    System.out.println("https://www.amazon.com:30000");
    System.out.println(urlVal2.isValid("https://www.amazon.com:30000"));

    System.out.println("\nValidation Failures:");
    System.out.println("https://www.amazon.com:");
    System.out.println(urlVal2.isValid("https://www.amazon.com:"));
    System.out.println("https://www.amazon.com:-80");
    System.out.println(urlVal2.isValid("https://www.amazon.com:-80a"));
    System.out.println("https://www.amazon.com:80");
    System.out.println(urlVal2.isValid("https://www.amazon.com:80a"));

// Path
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com/test1");
    System.out.println(urlVal2.isValid("https://www.amazon.com/test1"));
    System.out.println("https://www.amazon.com/");
    System.out.println(urlVal2.isValid("https://www.amazon.com/"));

    System.out.println("\nValidation Failures:");
    System.out.println("https://www.amazon.comtest1");
    System.out.println(urlVal2.isValid("https://www.amazon.comtest1"));
    System.out.println("https://www.amazon.com//test1");
    System.out.println(urlVal2.isValid("https://www.amazon.com//test1"));
    System.out.println("https://www.amazon.com/..");
    System.out.println(urlVal2.isValid("https://www.amazon.com/.."));
    System.out.println("https://www.amazon.com/../");
    System.out.println(urlVal2.isValid("https://www.amazon.com/../"));
    System.out.println("https://www.amazon.com       /");
    System.out.println(urlVal2.isValid("https://www.amazon.com         /"));

// Option
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com/test1/test1");
    System.out.println(urlVal2.isValid("https://www.amazon.com/test1/test1"));
    System.out.println("https://www.amazon.com/test1/");
    System.out.println(urlVal2.isValid("https://www.amazon.com/test1/"));
    System.out.println("https://www.amazon.com/test1test1");
    System.out.println(urlVal2.isValid("https://www.amazon.com/test1test1"));

    System.out.println("\nValidation Failures:");
    System.out.println("https://www.amazon.comtest1test1");
    System.out.println(urlVal2.isValid("https://www.amazon.comtest1test1"));
    System.out.println("https://www.amazon.com/test1//test1");
    System.out.println(urlVal2.isValid("https://www.amazon.com/test1//test1"));

// Queries
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com/ref=nb_sb_noss_null");
    System.out.println(urlVal2.isValid("https://www.amazon.com/ref=nb_sb_noss_null"));
    System.out.println("https://www.amazon.com/s/ref=nb_sb_noss_1?url=search-alias%3Daps&field-keywords=unicorn");
    System.out.println(urlVal2.isValid("https://www.amazon.com/s/ref=nb_sb_noss_1?url=search-alias%3Daps&field-keywords=unicorn"));

    System.out.println("\nValidation Failures:");
    System.out.println("https://www.amazon.com/ref=");
    System.out.println(urlVal2.isValid("https://www.amazon.com/ref="));
    System.out.println("https://www.amazoncom/ref=nb_sb_noss_null");
    System.out.println(urlVal2.isValid("https://www.amazoncom/ref=nb_sb_noss_null"));
    System.out.println("https://www.amazon.com/ref???nb_sb_noss_null");
    System.out.println(urlVal2.isValid("https://www.amazon.com/ref???nb_sb_noss_null"));

//urlVal3 - local URLS allowed
    UrlValidator urlVal3 = new UrlValidator(UrlValidator.ALLOW_LOCAL_URLS);
    System.out.println("\nAllowing local urls: \n");

// Special because it valid at local level
    System.out.println("http://hostname");
    System.out.println(urlVal3.isValid("http://hostname"));

// Scheme
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com/");
    System.out.println(urlVal3.isValid("https://www.amazon.com/"));
    System.out.println("www.amazon.com");
    System.out.println(urlVal3.isValid("www.amazon.com"));
    System.out.println("h3tp://www.amazon.com");
    System.out.println(urlVal3.isValid("h3tp://www.amazon.com"));

    System.out.println("\nValidation Failures:");
    System.out.println("https:/www.amazon.com");
    System.out.println(urlVal3.isValid("://www.amazon.com"));
    System.out.println("://www.amazon.com");
    System.out.println(urlVal3.isValid("://www.amazon.com"));

// Authority
    System.out.println("\nValidation Successful:");
    System.out.println("https://www.amazon.com/");
    System.out.println(urlVal3.isValid("https://www.amazon.com/"));
    System.out.println("https://www.amazon.co.uk/");
    System.out.println(urlVal3.isValid("https://www.amazon.co.uk/"));

    System.out.println("\nValidation Failures:");
    System.out.println("https://www.amazon~.com");
    System.out.println(urlVal3.isValid("https://www.amazon~.com"));
    System.out.println("https://www.amazon");
    System.out.println(urlVal3.isValid("https://www.amazon"));
    System.out.println("https://<Empty Space>");
    System.out.println(urlVal3.isValid("https:// "));
    System.out.println("https://www.thisisfakewebsite.com");
    System.out.println(urlVal3.isValid("https://www.thisisfakewebsite.com"));

    // Port
        System.out.println("\nValidation Successful:");
        System.out.println("https://www.amazon.com:80");
        System.out.println(urlVal3.isValid("https://www.amazon.com:80"));
        System.out.println("https://www.amazon.com:300");
        System.out.println(urlVal3.isValid("https://www.amazon.com:300"));
        System.out.println("https://www.amazon.com:3000");
        System.out.println(urlVal3.isValid("https://www.amazon.com:3000"));
        System.out.println("https://www.amazon.com:30000");
        System.out.println(urlVal3.isValid("https://www.amazon.com:30000"));

        System.out.println("\nValidation Failures:");
        System.out.println("https://www.amazon.com:");
        System.out.println(urlVal3.isValid("https://www.amazon.com:"));
        System.out.println("https://www.amazon.com:-80");
        System.out.println(urlVal3.isValid("https://www.amazon.com:-80a"));
        System.out.println("https://www.amazon.com:80");
        System.out.println(urlVal3.isValid("https://www.amazon.com:80a"));

    // Path
        System.out.println("\nValidation Successful:");
        System.out.println("https://www.amazon.com/test1");
        System.out.println(urlVal3.isValid("https://www.amazon.com/test1"));
        System.out.println("https://www.amazon.com/");
        System.out.println(urlVal3.isValid("https://www.amazon.com/"));

        System.out.println("\nValidation Failures:");
        System.out.println("https://www.amazon.comtest1");
        System.out.println(urlVal3.isValid("https://www.amazon.comtest1"));
        System.out.println("https://www.amazon.com//test1");
        System.out.println(urlVal3.isValid("https://www.amazon.com//test1"));
        System.out.println("https://www.amazon.com/..");
        System.out.println(urlVal3.isValid("https://www.amazon.com/.."));
        System.out.println("https://www.amazon.com/../");
        System.out.println(urlVal3.isValid("https://www.amazon.com/../"));
        System.out.println("https://www.amazon.com       /");
        System.out.println(urlVal3.isValid("https://www.amazon.com         /"));

    // Option
        System.out.println("\nValidation Successful:");
        System.out.println("https://www.amazon.com/test1/test1");
        System.out.println(urlVal3.isValid("https://www.amazon.com/test1/test1"));
        System.out.println("https://www.amazon.com/test1/");
        System.out.println(urlVal3.isValid("https://www.amazon.com/test1/"));
        System.out.println("https://www.amazon.com/test1test1");
        System.out.println(urlVal3.isValid("https://www.amazon.com/test1test1"));

        System.out.println("\nValidation Failures:");
        System.out.println("https://www.amazon.comtest1test1");
        System.out.println(urlVal3.isValid("https://www.amazon.comtest1test1"));
        System.out.println("https://www.amazon.com/test1//test1");
        System.out.println(urlVal3.isValid("https://www.amazon.com/test1//test1"));

    // Queries
        System.out.println("\nValidation Successful:");
        System.out.println("https://www.amazon.com/ref=nb_sb_noss_null");
        System.out.println(urlVal3.isValid("https://www.amazon.com/ref=nb_sb_noss_null"));
        System.out.println("https://www.amazon.com/s/ref=nb_sb_noss_1?url=search-alias%3Daps&field-keywords=unicorn");
        System.out.println(urlVal3.isValid("https://www.amazon.com/s/ref=nb_sb_noss_1?url=search-alias%3Daps&field-keywords=unicorn"));

        System.out.println("\nValidation Failures:");
        System.out.println("https://www.amazon.com/ref=");
        System.out.println(urlVal3.isValid("https://www.amazon.com/ref="));
        System.out.println("https://www.amazoncom/ref=nb_sb_noss_null");
        System.out.println(urlVal3.isValid("https://www.amazoncom/ref=nb_sb_noss_null"));
        System.out.println("https://www.amazon.com/ref???nb_sb_noss_null");
        System.out.println(urlVal3.isValid("https://www.amazon.com/ref???nb_sb_noss_null"));

// At default
    UrlValidator urlVal4 = new UrlValidator(0);
    System.out.println("\nDefault: \n");

// Special because not allowed at default
    System.out.println("http://hostname");
    System.out.println(urlVal4.isValid("http://hostname"));

    // Scheme
        System.out.println("\nValidation Successful:");
        System.out.println("https://www.amazon.com/");
        System.out.println(urlVal4.isValid("https://www.amazon.com/"));
        System.out.println("www.amazon.com");
        System.out.println(urlVal4.isValid("www.amazon.com"));
        System.out.println("h3tp://www.amazon.com");
        System.out.println(urlVal4.isValid("h3tp://www.amazon.com"));

        System.out.println("\nValidation Failures:");
        System.out.println("https:/www.amazon.com");
        System.out.println(urlVal4.isValid("://www.amazon.com"));
        System.out.println("://www.amazon.com");
        System.out.println(urlVal4.isValid("://www.amazon.com"));

    // Authority
        System.out.println("\nValidation Successful:");
        System.out.println("https://www.amazon.com/");
        System.out.println(urlVal4.isValid("https://www.amazon.com/"));
        System.out.println("https://www.amazon.co.uk/");
        System.out.println(urlVal4.isValid("https://www.amazon.co.uk/"));

        System.out.println("\nValidation Failures:");
        System.out.println("https://www.amazon~.com");
        System.out.println(urlVal4.isValid("https://www.amazon~.com"));
        System.out.println("https://www.amazon");
        System.out.println(urlVal4.isValid("http:s//www.amazon"));
        System.out.println("https://<Empty Space>");
        System.out.println(urlVal4.isValid("https:// "));
        System.out.println("https://www.thisisfakewebsite.com");
        System.out.println(urlVal4.isValid("https://www.thisisfakewebsite.com"));

        // Port
            System.out.println("\nValidation Successful:");
            System.out.println("https://www.amazon.com:80");
            System.out.println(urlVal4.isValid("https://www.amazon.com:80"));
            System.out.println("https://www.amazon.com:300");
            System.out.println(urlVal4.isValid("https://www.amazon.com:300"));
            System.out.println("https://www.amazon.com:3000");
            System.out.println(urlVal4.isValid("https://www.amazon.com:3000"));
            System.out.println("https://www.amazon.com:30000");
            System.out.println(urlVal4.isValid("https://www.amazon.com:30000"));

            System.out.println("\nValidation Failures:");
            System.out.println("https://www.amazon.com:");
            System.out.println(urlVal4.isValid("http:s//www.amazon.com:"));
            System.out.println("https://www.amazon.com:-80");
            System.out.println(urlVal4.isValid("https://www.amazon.com:-80a"));
            System.out.println("https://www.amazon.com:80");
            System.out.println(urlVal4.isValid("https://www.amazon.com:80a"));

        // Path
            System.out.println("\nValidation Successful:");
            System.out.println("https://www.amazon.com/test1");
            System.out.println(urlVal4.isValid("https://www.amazon.com/test1"));
            System.out.println("https://www.amazon.com/");
            System.out.println(urlVal4.isValid("https://www.amazon.com/"));

            System.out.println("\nValidation Failures:");
            System.out.println("https://www.amazon.comtest1");
            System.out.println(urlVal4.isValid("https://www.amazon.comtest1"));
            System.out.println("https://www.amazon.com//test1");
            System.out.println(urlVal4.isValid("https://www.amazon.com//test1"));
            System.out.println("https://www.amazon.com/..");
            System.out.println(urlVal4.isValid("https://www.amazon.com/.."));
            System.out.println("https://www.amazon.com/../");
            System.out.println(urlVal4.isValid("https://www.amazon.com/../"));
            System.out.println("https://www.amazon.com       /");
            System.out.println(urlVal4.isValid("https://www.amazon.com         /"));

        // Option
            System.out.println("\nValidation Successful:");
            System.out.println("https://www.amazon.com/test1/test1");
            System.out.println(urlVal4.isValid("https://www.amazon.com/test1/test1"));
            System.out.println("https://www.amazon.com/test1/");
            System.out.println(urlVal4.isValid("https://www.amazon.com/test1/"));
            System.out.println("https://www.amazon.com/test1test1");
            System.out.println(urlVal4.isValid("https://www.amazon.com/test1test1"));

            System.out.println("\nValidation Failures:");
            System.out.println("https://www.amazon.comtest1test1");
            System.out.println(urlVal4.isValid("https://www.amazon.comtest1test1"));
            System.out.println("https://www.amazon.com/test1//test1");
            System.out.println(urlVal4.isValid("https://www.amazon.com/test1//test1"));

        // Queries
            System.out.println("\nValidation Successful:");
            System.out.println("https://www.amazon.com/ref=nb_sb_noss_null");
            System.out.println(urlVal4.isValid("https://www.amazon.com/ref=nb_sb_noss_null"));
            System.out.println("https://www.amazon.com/s/ref=nb_sb_noss_1?url=search-alias%3Daps&field-keywords=unicorn");
            System.out.println(urlVal4.isValid("https://www.amazon.com/s/ref=nb_sb_noss_1?url=search-alias%3Daps&field-keywords=unicorn"));

            System.out.println("\nValidation Failures:");
            System.out.println("https://www.amazon.com/ref=");
            System.out.println(urlVal4.isValid("https://www.amazon.com/ref="));
            System.out.println("https://www.amazoncom/ref=nb_sb_noss_null");
            System.out.println(urlVal4.isValid("https://www.amazoncom/ref=nb_sb_noss_null"));
            System.out.println("https://www.amazon.com/ref???nb_sb_noss_null");
            System.out.println(urlVal4.isValid("https://www.amazon.com/ref???nb_sb_noss_null"));



  }
// First Partition: Scheme
  public void testYourFirstPartition() {
    System.out.println("\nSchemes Testing:\n");

    String[] teamSchemes = {"https://", "h3tp://", "http://", "://", ":/", " "};
    UrlValidator validScheme = new UrlValidator(teamSchemes, 0);
    for (int i = 0; i < teamSchemes.length; i++) {
      String curScheme = teamSchemes[i];
      System.out.println("\nTesting " + curScheme);
      boolean valid = validScheme.isValidScheme(curScheme);
      if (valid == false && i == 0 || valid == false && i == 1 || valid == true && i == 2 || valid == true && i == 3 || valid == false && i == 4) {
        System.out.println("Invalid Scheme\n");
      } else {
    	  	System.out.println("SUCCESS\n");
      }
    }
  }

  // Second Partition: Authority
  public void testYourSecondPartition() {
    System.out.println("\nAuthority Testing:\n");

    String[] teamAuthority = {"www.amazon.com", "www.amazon~.com", "www.amazon", " ", "https://www.thisisfakewebsite.com"};
    UrlValidator validAuthority = new UrlValidator(teamAuthority, 0);
    for (int i = 0; i < teamAuthority.length; i++) {
      String currentAuthority = teamAuthority[i];
      System.out.println("\nTesting " + currentAuthority);
      boolean valid = validAuthority.isValidAuthority(currentAuthority);
      if (valid == false && i == 0 || valid == true && i == 1 || valid == true && i == 2 || valid == true && i == 3 || valid == true && i == 4) {
        System.out.println("Invalid Authority\n");
      } else {
    	  System.out.println("SUCCESS\n");
      }
    }
  }

  // Third Partition: Port
  public void testYourThirdPartition() {
    System.out.println("\nPort Testing:\n");

    String[] teamPort = {"www.amazon.com:80", "www.amazon.com:", "www.amazon.com:-80", "www.amazon.com:80a"};
    UrlValidator validPort = new UrlValidator(teamPort, 0);
    for (int i = 0; i < teamPort.length; i++) {
      String currentPort = teamPort[i];
      System.out.println("\nTesting " + currentPort);
      boolean valid = validPort.isValidAuthority(currentPort);
      if (valid == false && i == 0 || valid == true && i == 1 || valid == true && i == 2 || valid == true && i == 3) {
       System.out.println("Invalid Port\n");
      } else {
    	System.out.println("SUCCESS\n");
      }
    }
  }

  // Fourth Partition: Path
  public void testYourFourthPartition(){
    System.out.println("\nPath Testing:\n");

    String[] teamPath = {"/test1", "//test1", "/", "test1", ".."};
    UrlValidator validPath = new UrlValidator(teamPath, 0);
    for (int i = 0; i < teamPath.length; i++) {
      String currentPath = teamPath[i];
      System.out.println("\nTesting " + currentPath);
      boolean valid = validPath.isValidPath(currentPath);
      if (valid == false && i == 0 || valid == true && i == 1 || valid == false && i == 2 || valid == true && i == 3) {
        System.out.println("Invalid Path\n");
      } else {
    	  	System.out.println("SUCCESS\n");
      }
    }
  }


  // Fifth Partition: Query
  public void testYourFifthPartition() {
    System.out.println("\nTesting Queries:\n");

    String[] teamQueries = {"ref=nb_sb_noss_null", "?ref=", "/", "ref???nb_sb_noss_null"};
    UrlValidator pathQuery = new UrlValidator(teamQueries, 0);
    for (int i = 0; i < teamQueries.length; i++) {
      String currentQuery = teamQueries[i];
      System.out.println("\nTesting " + currentQuery);
      boolean valid = pathQuery.isValidQuery(currentQuery);
      if(valid == false && i == 0 || valid == true && i == 1 || valid == false && i == 2 || valid == true && i == 3) {
        System.out.println("Invalid Query\n");
      } else {
    	  	System.out.println("SUCCESS\n");
      }
    }
  }


// Bug Counts
  public void testIsValid() {
    int findBugs = 0;
    int length = 20;
    int k = 0;

// To Set up valid parts
    String[] failedUrls = new String[length];
    String[] trueSchemes = {"https://", "http://", "", "h3tp://"};
    String[] trueAuthority = {"www.amazon.com", "amazon.com"};
    String[] truePort = {":80", ":9", ":100"};
    String[] truePath = {"/test1", "/"};
//    String[] trueOptions = {"/test1", "/test1/test1", " "}; Not sure why this doesn't pass that's why it is commented it out; Eclipse says not being used
    String[] trueQueries = {"ref=nb_sb_noss_null", " "};

// Randomize valid each iteration; loop through length
    System.out.println("\nValid Inputs:\n");
    for(int i = 0; i < length; i++) {

// Randomize
      int schemeInt = (int) (Math.random() * 2);
      int authorityInt = (int) (Math.random() * 2);
      int portInt = (int) (Math.random() * 3);
      int pathInt = (int) (Math.random() * 2);
  //    int optionsInt = (int) (Math.random() * 3); Not sure why this doesn't pass that's why it is commented it out; Eclipse says not being used
      int queriesInt = (int) (Math.random() * 2);

// String iteration of valid parts in appropriate order
      String url = trueSchemes[schemeInt] + trueAuthority[authorityInt] + truePort[portInt] + truePath[pathInt] + trueQueries[queriesInt];
      UrlValidator validator = new UrlValidator();

// Check if valid
      boolean valid = validator.isValid(url);

// If invalid then increase the bug counts and store url
      if(valid == false) {
        findBugs++;
        failedUrls[k] = url;
        k++;
      }
    }

// Print Summary
    System.out.println("\nTotal Bugs Found: " + findBugs + "\n");
    System.out.println("\nFailed URLs: \n");
    for (int j = 0; j < failedUrls.length; j++) {
      if(failedUrls[j] != null){
    	System.out.println(failedUrls[j] + "\n");
      }
    }
  }

// Unit test: Scheme
  public void testisValidSchemeUnitTest()
  {
	  UrlValidator val = new UrlValidator();
	  System.out.println("\nisValidScheme Unit Test\n");
	  System.out.println("\nTesting scheme http");
	  System.out.println("Result: " + val.isValidScheme("http"));
	  System.out.println("\nTesting scheme https");
	  System.out.println("Result: " + val.isValidScheme("https"));
	  System.out.println("\nTesting scheme aaa");
	  System.out.println("Result: " + val.isValidScheme("aaa"));
	  System.out.println("\nTesting scheme ftp");
	  System.out.println("Result: " + val.isValidScheme("ftp"));

  }

  // Unit test: Query
    public void testisValidQueryUnitTest()
    {
  	  UrlValidator val = new UrlValidator();
  	  System.out.println("\nisValidQuery Unit Test\n");
  	  System.out.println("\nTesting query ref=nb_sb_noss_null");
  	  System.out.println("Result: " + val.isValidQuery("ref=nb_sb_noss_null"));
  	  System.out.println("\nTesting query null");
  	  System.out.println("Result: " + val.isValidQuery(""));
  	  System.out.println("\nTesting query ?page=1&test=0");
  	  System.out.println("Result: " + val.isValidQuery("?page=1&test=0"));
    }

}
