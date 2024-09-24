public class Main {
	public static void main(String[] args) {
		Shape f1 = new Square(2,3, 1);
		Shape f2 = new Circle(4, 2, 3);
		Shape f3 = new Line(3, 2, 6,1);

		f1.draw();
		f2.draw();
		f3.draw();

		f1.move(9,5);
		f2.move(9,5);
		f3.move(9,5);

		f1.draw();
		f2.draw();
		f3.draw();
	}
}

