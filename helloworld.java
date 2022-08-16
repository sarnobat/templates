import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.SequenceInputStream;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * find | /usr/local/Cellar/openjdk@11/11.0.12/bin/java helloworld.java
 */
public class Main {
	public static void main(String args[]) {

		// 4) cli options
		if (System.getProperties().containsKey("-h")) {
			System.out.println(help());
			System.exit(-1);
			throw new RuntimeException("so java compiles");
		}
		// 5) map/dictionary/associative array
		Map<String, String> map = new HashMap<>();

		// 8) concurrent
		try (BufferedReader bufferedReader = read(args, System.in)) {

			// 1) stdin loop (with optional file arg)
			for (String line = bufferedReader.readLine(); line != null; line = bufferedReader.readLine()) {
				System.out.println(line);

				// 2) regex capture groups

				// 10) web scrape
				// 6) embed shell code inside high level language connecting pipes
				// 9) print with padding
				// 10) write to file

			}

			// 10) print current date
			// 7) convert epoch to date and vv

		} catch (IOException e) {
			System.err.println("Error: Target File Cannot Be Read");
		}
	}

	private static BufferedReader read(String[] args, InputStream in) throws IOException {
		BufferedReader br;
		BufferedReader br1 = new BufferedReader(new InputStreamReader(in));

		if (br1.ready()) {
			br = br1;
			// problem: arg files get ignored
		} else {
			if (args.length == 0) {
				System.out.println(help());
				System.exit(-1);
				throw new RuntimeException("so java compiles");
			} else {
				SequenceInputStream is = new SequenceInputStream(Collections.enumeration(Arrays.stream(args).map(f -> {
					try {
						
						// Check file exists
						
						// 3) parse file path

						// 1) file read
						return new FileInputStream(f);
					} catch (FileNotFoundException e) {
						throw new RuntimeException(e);
					}
				}).collect(Collectors.toList())));
				br = new BufferedReader(new InputStreamReader(is));
			}
		}
		return br;
	}

	private static String help() {
		String help = "usage: helloworld [ARGS]";
		return help;
	}
}