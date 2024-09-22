public class Main {
	public static void main(String[] args) {
		Shape f1 = new Square(new Point(2,3), 1);
		Shape f2 = new Circle(new Point(4,2), 3);
		Shape f3 = new Line(new Point(3,2), new Point(6,1));

		System.out.println(f1.draw());
		System.out.println(f2.draw());
		System.out.println(f3.draw());

		f1.move(9,5);
		f2.move(9,5);
		f3.move(9,5);

		System.out.println(f1.draw());
		System.out.println(f2.draw());
		System.out.println(f3.draw());
	}
}

