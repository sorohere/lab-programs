package javaa.lab2.Q2.PackageP2;
import javaa.lab2.Q2.PackageP1.*;

public class three extends two{
   int z;
   
    public three (int x, int y, int z) {
        super(x, y);
        this.z = z;
    }
    
    public three () {
        super(0, 0);
        this.z = 0;
    }

    public String toString() {
        return super.toString() + " z: " + z;
    }
}