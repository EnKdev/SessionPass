using System;

namespace EnKdev.SessionPass.Tests
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string otsvCode = "";
            PhpIntegration pi = new PhpIntegration();
            otsvCode = pi.RequestOtsvCode(0);
            Console.WriteLine("TEST1: Code Checking (codeFlag=0)");
            Console.WriteLine("Received One-Time-Session-Verification Code: {0}", otsvCode);
            Console.WriteLine("Checking for integrity...");
            bool isSame;
            isSame = pi.CompareOtsvCode(otsvCode, 0);

            if (isSame)
                Console.WriteLine("One-Time-Session-Verification Code is the same as it is in Database!");
            else
                Console.WriteLine("One-Time-Session-Verification Code is not the same as it is in Database!");

            Console.WriteLine("----------");
            
            otsvCode = pi.RequestOtsvCode(1);
            Console.WriteLine("TEST2: Code Checking (codeFlag=1)");
            Console.WriteLine("Received One-Time-Session-Verification Code: {0}", otsvCode);
            Console.WriteLine("Checking for integrity...");
            isSame = pi.CompareOtsvCode(otsvCode, 1);

            if (isSame)
                Console.WriteLine("One-Time-Session-Verification Code is the same as it is in Database!");
            else
                Console.WriteLine("One-Time-Session-Verification Code is not the same as it is in Database!");
            
            Console.WriteLine("----------");
            
            otsvCode = pi.RequestOtsvCode(2);
            Console.WriteLine("TEST2: Code Checking (codeFlag=2)");
            Console.WriteLine("Received One-Time-Session-Verification Code: {0}", otsvCode);
            Console.WriteLine("Checking for integrity...");
            isSame = pi.CompareOtsvCode(otsvCode, 2);

            if (isSame)
                Console.WriteLine("One-Time-Session-Verification Code is the same as it is in Database!");
            else
                Console.WriteLine("One-Time-Session-Verification Code is not the same as it is in Database!");

            Console.WriteLine("----------");
            
            Console.WriteLine("TEST4: Code-Faking");
            Console.WriteLine("Setting otsvCode to abskd");
            otsvCode = "abskd";
            Console.WriteLine("Checking for code-integrity...");
            isSame = pi.CompareOtsvCode(otsvCode, 0);

            if (isSame)
                Console.WriteLine("One-Time-Session-Verification Code is the same as it is in Database!");
            else
                Console.WriteLine("One-Time-Session-Verification Code is not the same as it is in Database!");
            
            Console.WriteLine("----------");
            Console.WriteLine("TEST5: Sending a null terminated string to the server");
            Console.WriteLine("Setting otsvCode to null");
            otsvCode = null;
            Console.WriteLine("Checking for code-integrity...");
            isSame = pi.CompareOtsvCode(otsvCode, 0);
            
            Console.ReadKey();
        }
    }
}