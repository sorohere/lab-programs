import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class ReverseNumberApplet extends Applet implements ActionListener, KeyListener {
    TextField textField;
    Label label;

    public void init() {
        label = new Label("Type a number and press 'J' to see its reverse:");
        textField = new TextField(10);
        textField.addKeyListener(this);
        add(label);
        add(textField);
    }

    public void actionPerformed(ActionEvent e) {
        // This method is not used in this example
    }

    public void keyTyped(KeyEvent e) {
        // This method is not used in this example
    }

    public void keyPressed(KeyEvent e) {
        // This method is not used in this example
    }

    public void keyReleased(KeyEvent e) {
        if (e.getKeyChar() == 'J') {
            String numberStr = textField.getText();
            try {
                int number = Integer.parseInt(numberStr);
                int reversedNumber = reverseNumber(number);
                showStatus("Reversed number: " + reversedNumber);
            } 
            catch (NumberFormatException ex) {
                showStatus("Invalid input: Please enter a valid number.");
            }
        }
    }

    private int reverseNumber(int number) {
        int reversedNumber = 0;
        while (number != 0) {
            int digit = number % 10;
            reversedNumber = reversedNumber * 10 + digit;
            number /= 10;
        }
        return reversedNumber;
    }
}
