import scala.io.StdIn

object ReadLines {
  def main(args: Array[String]): Unit = {
    var line: String = StdIn.readLine()
    while (line != null) {
      line = StdIn.readLine()
      println("[prefix] " + line)

    }
  }
}
