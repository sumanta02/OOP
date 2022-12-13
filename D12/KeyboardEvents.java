import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class KeyboardEvents extends Applet implements KeyListener {
   
   TextArea area, l;

   public KeyboardEvents() {
      l = new TextArea();
      l.setEditable(false);
      l.setBounds(10, 350, 500, 500);
      area = new TextArea();
      area.setBounds(10, 10, 300, 300);
      area.addKeyListener(this);
      add(l);
      add(area);
      setSize(400, 400);
      setLayout(null);
      setVisible(true);
   }

   public void keyPressed(KeyEvent e) {
      displayInfo(e, "Key Pressed: ");
   }

   public void keyReleased(KeyEvent e) {
      displayInfo(e, "Key Released: ");
   }

   public void keyTyped(KeyEvent e) {
      displayInfo(e, "Key Typed: ");
   }

   void displayInfo(KeyEvent e, String output) {
      int id = e.getID();
        String keyString;
        if (id == KeyEvent.KEY_TYPED) {
            char c = e.getKeyChar();
            keyString = "key character = '" + c + "'";
        } else {
            int keyCode = e.getKeyCode();
            keyString = "key code = " + keyCode
                    + " ("
                    + KeyEvent.getKeyText(keyCode)
                    + ")";
        }
      int modifiersEx = e.getModifiersEx();
      String modString = "extended modifiers = " + modifiersEx;
      String tmpString = KeyEvent.getModifiersExText(modifiersEx);
        if (tmpString.length() > 0) {
            modString += " (" + tmpString + ")";
        } else {
            modString += " (no extended modifiers)";
        }
        
        String actionString = "action key? ";
        if (e.isActionKey()) {
            actionString += "YES";
        } else {
            actionString += "NO";
        }
        l.setText(output + "\n" + keyString + "\n" + modString + "\n" + actionString + "\n");
   }

   public void init() {
      new KeyboardEvents();
   }
}
/*
 * 
 * <applet code = KeyboardEvents.class width=400 height=400>
 * 
 * </applet>
 * 
 */