using System;
using System.Collections.Specialized;
using System.Net;
using System.Text;

namespace EnKdev.SessionPass.Tests
{
    public class PhpIntegration
    {
        public string RequestOtsvCode(int codeFlag)
        {
            var res = HttpHelper.HttpPost("https://enkdev.xyz/cdn/php/sessionpass/generateOtsvCode.php",
                new NameValueCollection()
                {
                    {"cf", codeFlag.ToString()}
                });

            UTF8Encoding utf = new UTF8Encoding();
            string otsvCode = utf.GetString(res);

            return otsvCode;
        }

        public bool CompareOtsvCode(string otsvCode, int codeFlag)
        {
            bool isSame = false;

            if (otsvCode != null && codeFlag != null)
            {
                var res = HttpHelper.HttpPost("https://enkdev.xyz/cdn/php/sessionpass/compareCode.php",
                    new NameValueCollection()
                    {
                        {"code", otsvCode},
                        {"cf", codeFlag.ToString()}
                    });
                
                try
                {
                    UTF8Encoding utf = new UTF8Encoding();
                    string response = utf.GetString(res);

                    if (response == "true")
                        isSame = true;
                }
                catch (WebException e)
                {
                    Console.Write(e.Message);
                }
            }
            else
                Console.WriteLine("otsvCode is null, can't check.");

            return isSame;
        }
    }

    public static class HttpHelper
    {
        public static byte[] HttpPost(string uri, NameValueCollection pairs)
        {
            byte[] res = null;

            using (WebClient client = new WebClient())
                res = client.UploadValues(uri, pairs);

            return res;
        }
    }
}