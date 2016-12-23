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

    Iterator<String> iterator = list.iterator();
    while( iterator.hasNext())
      System.out.println( PrintNextCode(iterator.next()));

  }

  public static String PrintNextCode( String code )
  {
    int i = code.length()-1, j = code.length() - 2;
    boolean found = false;

    while( !found && j >= 0 )
    {
      if( code[j] < code[i] )
      {
        code[i] = (char)((int)code[i] + (int)code[j]);
        code[j] = (char)((int)code[i] - (int)code[j]);
        code[i] = (char)((int)code[i] - (int)code[j]);
        found = true;
      }

      i--;
      j--;
    }
  }
}
