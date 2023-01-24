import java.util.function.Function;
import java.util.function.Predicate;

public class List<T> {
    T head;
    List<T> tail = null;

    public List(T head) {
        this.head = head;
    }

    public List(T... elements) {
        List<T> cur = this;
        this.head = elements[0];
        for (int i = 1; i < elements.length; i++) {
            if (i < elements.length - 1) cur.tail = new List<T>(elements[i]);
            cur = cur.tail;
        }
    }

    public List(T head, List<T> tail) {
        this.head = head;
        this.tail = tail;
    }

    public List<T> filter(Predicate<T> func) {
        if (func.test(this.head)) {
            return new List<T>(this.head, this.tail == null ? null : this.tail.filter(func));
        } else {
            return this.tail == null ? null : this.tail.filter(func);
        }
    }

    public <U> List<U> map(Function<T, U> func) {
        return new List<U>(
            func.apply(this.head),
            this.tail == null ? null : this.tail.map(func)
        );
    }
    
    public boolean isEmpty() {
        return this.head == null;
    }
    
    public String toString() {
        return "[" + this.head + ", " + (this.tail == null ? "*" : this.tail.toString()) + "]";
    }
    public static void main(String args[]) {
        List<Integer> a = new List<Integer>(1, 2, 3, 4);
        System.out.println(a);

        List<Integer> b = a.filter(x -> x % 2 == 0).map(x -> (int)Math.pow(x, 2));
        System.out.println(b);

        List<Integer> c = a.map(x -> (int)Math.pow(x, 2));
        System.out.println(c);
    }
}