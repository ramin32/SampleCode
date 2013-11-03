/*************************************************************
 * BallAquarium.java
 * An aquarium of balls jumping around in random directions
 * at random speeds.
 *
 * Author:
 * Ramin Rakhamimov 
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 *************************************************************/

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Point;
import java.awt.Graphics;
import java.awt.Color;
import java.awt.Dimension;
import java.util.Random;

public class BallAquarium extends JPanel implements ActionListener
{
    private Ball[] balls;
    private final int size;

    public BallAquarium(int size)
    {
        this.size = size;
    }

    public void actionPerformed(ActionEvent evt)
    {
        repaint();
    }

    @Override
        public void paintComponent(Graphics g)
        {
            if(balls == null)
            {

                balls = new Ball[size];
                for(int i = 0; i < size; i++)
                    balls[i] = Ball.generateBall(this.getWidth(), this.getHeight());
            }

            g.clearRect(0,0, this.getWidth(), this.getHeight());
            for(Ball b:balls)
            {
                b.draw(g);
                b.updatePosition(this.getWidth(), this.getHeight());
            }

        }

    public static void main(String...args)
    {

        // Init aquarium
        int balls = 200;
        BallAquarium aquarium = new BallAquarium(balls);
        aquarium.setPreferredSize(new Dimension(500,500));

        // Set up frame with aquarium
        JFrame frame = new JFrame("Ball Aquarium");
        frame.add(aquarium);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        // Set up timer
        int delay = 30; //milliseconds
        new Timer(delay, aquarium).start();
    }
}

class Ball
{
    private static final Random RANDOM = new Random(System.currentTimeMillis());
    private static final int DIAMETER = 15;
    private static final int[] INCREMENTS = new int[]{1,-1};

    private int xIncrement;
    private int yIncrement;
    private int xPos;
    private int yPos;
    private Color color;

    private Ball(){}
    public static Ball generateBall(int maxX, int maxY)
    {
        Ball b = new Ball();

        b.xIncrement = INCREMENTS[RANDOM.nextInt(1)] * RANDOM.nextInt(10) + 1;
        b.yIncrement = INCREMENTS[RANDOM.nextInt(1)] * RANDOM.nextInt(10) + 1;
        b.xPos = RANDOM.nextInt(maxX-DIAMETER);
        b.yPos = RANDOM.nextInt(maxY-DIAMETER);
        b.color = new Color(RANDOM.nextInt(255), RANDOM.nextInt(255), RANDOM.nextInt(255));

        return b;
    }

    public void updatePosition(int maxX, int maxY)
    {
        if(xPos + DIAMETER > maxX || xPos < 0)
            xIncrement *= -1;
        if(yPos + DIAMETER > maxY || yPos < 0)
            yIncrement *= -1;

        xPos += xIncrement;
        yPos += yIncrement;
    }

    public void draw(Graphics g)
    {
        g.setColor(color);
        g.fillOval(xPos, yPos, DIAMETER, DIAMETER);
    }
}
