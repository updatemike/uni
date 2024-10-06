public class Form {
    
        private int _id;
        private static int _last = 0;
    
        protected Form() {
            _id = ++_last;
        }
        public int id() { return _id; }
    
    
}
