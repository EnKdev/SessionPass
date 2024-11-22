package xyz.enkdev.sessionpass

import java.net.URI
import java.net.URLEncoder
import javax.net.ssl.HttpsURLConnection

/**
 * Provides mechanisms to send POST requests with a payload to a server
 */
class HttpHelper {
    companion object {
        /**
         * Sends an HTTP POST request with a given payload to a server.
         * 
         * @param uri The target URL where the POST request should be sent to.
         * @param pairs The payload of the POST request.
         * 
         * @returns A byte array containing the response from the webserver.
         */
        fun httpPost(uri: String, pairs: Map<String, String>): ByteArray? {
            val url = URI(uri);
            val conn = url.toURL().openConnection() as HttpsURLConnection;
            
            conn.requestMethod = "POST";
            conn.doOutput = true;
            conn.setRequestProperty("Content-Type", "application/x-www-form-urlencoded")
            
            val data = pairs.map {
                "${URLEncoder.encode(it.key, "UTF-8")}=${URLEncoder.encode(it.value, "UTF-8")}"
            }.joinToString("&")
            
            conn.outputStream.use() { os ->
                os.write(data.toByteArray())
            }
            
            return conn.inputStream.readBytes()
        }
    }
}