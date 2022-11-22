import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class KeyboardEvents extends Applet implements KeyListener {
   Label l;
   TextArea area;

   public KeyboardEvents() {
      l = new Label();
      l.setBounds(20, 50, 100, 20);
      area = new TextArea();
      area.setBounds(20, 80, 300, 300);
      area.addKeyListener(this);
      add(l);
      add(area);
      setSize(400, 400);
      setLayout(null);
      setVisible(true);
   }

   public void keyPressed(KeyEvent e) {
      l.setText("Key Pressed: " + e.getKeyChar());
   }

   public void keyReleased(KeyEvent e) {
      l.setText("Key Released: " + e.getKeyChar());
   }

   public void keyTyped(KeyEvent e) {
      l.setText("Key Typed: " + e.getKeyChar());
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