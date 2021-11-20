using System.Collections.Specialized;
using System.Net;

namespace EnKdev.SessionPass
{
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