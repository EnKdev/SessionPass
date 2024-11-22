package xyz.enkdev.sessionpass.test

import xyz.enkdev.sessionpass.OtsvCode

fun main() {
    var otsvCode: String? = ""
    var isSame: Boolean
    var oc = OtsvCode()

    println("TEST1: Code Check - Small (codeFlag=0)")
    otsvCode = oc.requestOtsvCode(0)
    println("Received One-Time-Session-Verification Code: ${otsvCode}")
    println("Checking for integrity...")
    isSame = oc.compareOtsvCode(otsvCode, 0)
    evalComparison(isSame)

    println("-----------")

    println("TEST2: Code Check - Middle (codeFlag=1)")
    otsvCode = oc.requestOtsvCode(1)
    println("Received One-Time-Session-Verification Code: ${otsvCode}")
    println("Checking for integrity...")
    isSame = oc.compareOtsvCode(otsvCode, 1)
    evalComparison(isSame)

    println("-----------")

    println("TEST3: Code Check - Large (codeFlag=2)")
    otsvCode = oc.requestOtsvCode(2)
    println("Received One-Time-Session-Verification Code: ${otsvCode}")
    println("Checking for integrity...")
    isSame = oc.compareOtsvCode(otsvCode, 2)
    evalComparison(isSame)

    println("-----------")

    println("TEST4: Code Faking")
    println("Setting otsvCode to abskd")
    otsvCode = "abskd"
    println("Checking for integrity...")
    isSame = oc.compareOtsvCode(otsvCode, 0)
    evalComparison(isSame)

    println("-----------")

    println("TEST5: Null-Terminated string")
    println("Setting otsvCode to null")
    otsvCode = null
    println("Checking for integrity...")
    isSame = oc.compareOtsvCode(otsvCode, 0)

    readln()
}
    
private fun evalComparison(isSame: Boolean) {
    if (isSame) {
        println("Code integrity is OK.")
    } else {
        println("Code integrity is NOT OK.")
    }
}