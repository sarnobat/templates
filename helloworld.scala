// Looks like conversion to a native image can only be done inside an sbt project, not like go build.

import scala.io.StdIn

object HelloWorld {
  def main(args: Array[String]): Unit = {
    var line: String = StdIn.readLine()
    while (line != null) {
      line = StdIn.readLine()
      println("[prefix] " + line)

    }
  }
}
