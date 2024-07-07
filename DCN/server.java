import java.net.*;
import java.io.*;

public class server {
    public static void main(String[] args) throws Exception {
        ServerSocket s1 = new ServerSocket(4000);
        System.out.println("Server ready for connection");

        Socket s2 = s.accept();

        System.out.println("Connection is successful and waiting for chatting");

        InputStream i = s1.getInputStream();
        BufferedReader r1 = new BufferedReader(new InputStreamReader(istream));

        String fname = r1.readLine();
        BufferedReader r2 = new BufferedReader(new FileReader(fname));

        OutputStream o = s2.getOutputStream();
        PrintWriter p = new PrintWriter(o, true);

        String str;

        while ((str = r2.readLine()) != null) {
            p.println(str);
        }

        s2.close();
        s1.close();
        p.close();
        r1.close();
        r2.close();
    }
}
