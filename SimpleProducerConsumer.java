/*******************************************************
 * SimplerProducerConsumer.java
 *
 * A simple consumer producer example, with very basic synchronization
 * methods.
 *
 *     OUTPUT:
 *     Producer put: 2276
 *     Consumer got: 2276
 *     Consumer got: 1376
 *     Producer put: 1376
 *     Producer put: 3882
 *     Consumer got: 3882
 *     Consumer got: 2387
 *     Producer put: 2387
 *     Consumer got: 1014
 *     Producer put: 1014
 *     And so on....
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 ******************************************************/ 
import java.util.Random;

public class SimpleProducerConsumer{
    static class Producer implements Runnable{
        private Service service;

        Producer(Service service){
            this.service = service;
        }
        public void run() {
            Random rand = new Random(System.currentTimeMillis());
            while(true){
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                int num = rand.nextInt(5000);
                while(!service.isEmpty());
                service.setValue(num);
                System.out.println("Producer put: " + num);

                
            }

        }
    }

    static class Consumer implements Runnable{
        private Service service;

        Consumer(Service service){
            this.service = service;
        }
        public void run() {
            while(true){
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                while(service.isEmpty());
                System.out.println("Consumer got: " + service.getValue());
            }

        }
    }

    public static class Service{
        int i;
        boolean empty = true;

        public void setValue(int i){
            this.i = i;
            empty = false;
        }
        public int getValue(){
            empty = true;
            return i;
        }

        public boolean isEmpty(){
            return empty;
        }
    }

    public static void main(String[] args){
        Service service = new Service();
        Thread consumerThread = new Thread(new Consumer(service));
        Thread producerThread = new Thread(new Producer(service));

        consumerThread.start();
        producerThread.start();
    }
}
