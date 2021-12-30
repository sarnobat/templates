import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
 
 /**
 * find | /usr/local/Cellar/openjdk@11/11.0.12/bin/java helloworld.java
 */
public class HelloWorld {
    public static void main(String args[]) {
	   try{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

			for (String line = br.readLine(); line != null; line = br.readLine()) {
			   System.out.println(line);
			}

			br.close();
		}
		catch(Exception e){
			System.err.println("Error: Target File Cannot Be Read");
		}
    }
}