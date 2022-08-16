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
import java.util.List;
import java.util.stream.Collectors;

/**
 * find | /usr/local/Cellar/openjdk@11/11.0.12/bin/java helloworld.java
 */
public class Main {
	public static void main(String args[]) {
		try (BufferedReader bufferedReader = read(args, System.in)) {

			for (String line = bufferedReader.readLine(); line != null; line = bufferedReader.readLine()) {
				System.out.println(line);
			}

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
				System.out.println("usage: helloworld [ARGS]");
				System.exit(-1);
				throw new RuntimeException("so java compiles");
			} else {
				SequenceInputStream is = new SequenceInputStream(Collections.enumeration(Arrays.stream(args).map(f -> {
					try {
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
}