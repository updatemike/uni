package pencilcase;
import java.util.*;

public class PencilCase {
    private final int _capacity;
    private LinkedList<Pencil> _pencils = new LinkedList<>();
    public PencilCase(int capacity) {_capacity = capacity;}
    public void addPencil(Pencil p) {if(_pencils.size() < _capacity)_pencils.add(p);}
    public int countEqual(Pencil pencil) {
        int counter = 0;
        for(Pencil p : _pencils) {if(p.equals(pencil)) counter++;}
        return counter;
    }
    public void removePencil(Pencil pencil) {_pencils.remove(pencil);}
    public void removeAllColor(String color) {
        Iterator<Pencil> iter = _pencils.iterator();
        Pencil p;
        while(iter.hasNext()) {
            p = iter.next();
            if(p.getColor().equals(color)) iter.remove();
        }
    }
    public Collection<Pencil> getAllOrderedBrandColor() {
        LinkedList<Pencil> list = new LinkedList<>(_pencils);
        Collections.sort(list,new PencilOrderByBrandColor());
        return Collections.unmodifiableCollection(list);
    }
    public Collection<Pencil> getAll() {
        return Collections.unmodifiableCollection(_pencils);
    }

    public static void main(String[] args) {
        Pencil p1 = new Pencil("Brand1", "White");
        Pencil p2 = new Pencil("Brand2", "White");
        Pencil p3 = new Pencil("Brand1", "White");
        Pencil p4 = new Pencil("Brand3", "Yellow");
        Pencil p5 = new Pencil("Brand4", "White");
        Pencil p6 = new Pencil("Brand2", "Black");
        Pencil p7 = new Pencil("Brand3", "Yellow");
        Pencil p8 = new Pencil("Brand1", "White");
        Pencil p9 = new Pencil("Brand2", "Brown");
        System.out.println("------------------------------");
        Collection<Pencil> col;
        PencilCase pc = new PencilCase(8);

        pc.addPencil(p1);
        pc.addPencil(p2);
        pc.addPencil(p3);
        pc.addPencil(p4);
        pc.addPencil(p5);
        pc.addPencil(p6);
        pc.addPencil(p7);
        pc.addPencil(p8);
        pc.addPencil(p9);

        col = pc.getAll();
        for (Pencil p : col) System.out.println(p);
        System.out.println("------------------------------");
        col = pc.getAllOrderedBrandColor();
        for (Pencil p : col) System.out.println(p);
        System.out.println("------------------------------");
        col = pc.getAll();
        for (Pencil p : col) System.out.println(p);
        System.out.println("------------------------------");
    }
}