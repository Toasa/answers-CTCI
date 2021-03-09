public class RunnableThreadExample implements Runnable {
    public int count = 0;

    public void run() {
        System.out.println("RunnableThread starting");
        try {
            while (count < 5) {
                Thread.sleep(500);
                count++;
            }
        } catch (InterruptException exc) {
            System.out.println("RunnableThread interrupted");
        }
        System.out.println("RunnableThread terminating");
    }
}

public static void main(String[] args) {
    RunnableThreadExample instance = new RunnableThreadExample();
    Thread th = new Thread(instance);
    th.start();

    while (instance.count != 5) {
        try {
            Thread.sleep(250);
        } catch (InterruptException exc) {
            exc.printStackTrace();
        }
    }
}

