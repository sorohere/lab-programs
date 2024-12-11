package abc;
import java.sql.*;

public class emp {
  public static void main(String[] args) {
    String url = "jdbc:mysql://localhost:3306/";
    String user = "root";
    String pass = "";

    String q1 = "create database if not exists mydb";
    String q2 = "create table emp(id int primary key, fname varchar(20), lname varchar(20), project varchar(20), salary float)";
    String q3 = "insert into emp values (1, 'a', 'a', 'p1', 100.0), (2, 'b', 'b', 'p2', 200.0), (3, 'c', 'c', 'p3', 150.0)";

    String q4 = "select * from emp";
    String q5 = "select id, fname from emp where project='webdev'";

    try {
      Connection conn = DriverManager.getConnection(url, user, pass);
      Statement stmt = conn.createStatement();

      ResultSet rs = stmt.executeUpdate(q1);
      conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", user, pass);
      stmt = conn.createStatement();
      
      ResultSet rs = stmt.executeUpdate(q2);
      ResultSet rs = stmt.executeUpdate(q3);

      ResultSet rs1 = stmt.executeQuery(q4);
      while(rs.next()) System.out.println(rs.getInt("ID") + rs.getString("FName") + rs.getString("LName") + rs.getString("Project") + rs.getFloat("Salary"));
            
      ResultSet rs2 = stmt.executeQuery(q5);
      while(rs.next()) System.out.println(rs.getInt("ID") + rs.getString("FName") + rs.getString("LName") + rs.getString("Project") + rs.getFloat("Salary"));
    }
    catch(SQLException e) e.printStackTrace();
  }
}
