import java.util.Queue
import java.util.LinkedList
import kotlin.collections.*
import java.io.PrintWriter
import kotlin.math.*
import java.util.Scanner
import java.lang.Math.floorMod
import java.lang.Math.floorDiv
import java.io.File
import kotlin.comparisons.compareBy
 
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out
 
const val _BUFFER_SIZE = 1 shl 16
@JvmField val _buffer = ByteArray(_BUFFER_SIZE)
@JvmField var _bufferPt = 0
@JvmField var _bytesRead = 0
 
tailrec fun readChar(): Char {
    if(_bufferPt == _bytesRead) {
        _bufferPt = 0
        _bytesRead = INPUT.read(_buffer, 0, _BUFFER_SIZE)
    }
    return if(_bytesRead < 0) Char.MIN_VALUE
    else {
        val c = _buffer[_bufferPt++].toChar()
        if (c == '\r') readChar() else c
    }
}
 
/** @param skipNext Whether to skip the next character (usually whitespace), defaults to true */
fun readCharArray(n: Int, skipNext: Boolean = true): CharArray {
    val res = CharArray(n) { readChar() }
    if(skipNext) readChar()
    return res
}
 
fun readLine(): String? {
    var c = readChar()
    return if(c == Char.MIN_VALUE) null
    else buildString {
        while(c != '\n' && c != Char.MIN_VALUE) {
            append(c)
            c = readChar()
        }
    }
}
fun readLn() = readLine()!!
 
fun read() = buildString {
    var c = readChar()
    while(c <= ' ') {
        if(c == Char.MIN_VALUE) return@buildString
        c = readChar()
    }
    do {
        append(c)
        c = readChar()
    } while(c > ' ')
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }
 
@JvmField val _writer = PrintWriter(OUTPUT, false)

fun main() { _writer.solve(); _writer.flush() }

// val mxn=3000
val INF=1000000007
// kotlinc test.kt -include-runtime -d test.jar && java -jar test.jar
// var adj=MutableList (mxn) {mutableListOf<Pair<Int, Int>> ()}
// var adj=MutableList (mxn) {mutableListOf<Int> ()}
// var vis=BooleanArray(mxn)
// var a=IntArray(mxn)
// var ok=true
// var n=0





fun PrintWriter.solve() {
    var t=1
    t=readInt()
    while(t>0)
    {
        t--
        // var (a,b) = readLine()!!.trim().split("\\s+".toRegex()).map (String::toInt)
        // var arr=readLine()!!.split(" ").map {it.toInt()} (read array)
        // var(n,a) = readLine()!!.split(' ').map{it.toInt()}
    }
}
