import java.util.*;
import java.io.*;

public class IDCodes
{
  public static void main( String[] args )
  {
    String s;
    List<String> list = new ArrayList<String>();
    BufferedReader input = new BufferedReader( new InputStreamReader( System.in ));

    try
    {
      while(( s = input.readLine() ) != null && s.indexOf("#") == -1 )
      {
        list.add(s);
        System.out.println(s);
      }
    }

    catch( IOException e )
    {}
  }
}
