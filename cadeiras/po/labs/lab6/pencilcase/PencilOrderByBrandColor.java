package pencilcase;
import java.util.Comparator;

public class PencilOrderByBrandColor implements Comparator<Pencil>{
    @Override
    public int compare(Pencil p1, Pencil p2) {
        int comp = p1.getBrand().compareTo(p2.getBrand());
        if(comp == 0) return p1.getColor().compareTo(p2.getColor());
        return comp;
    }
}