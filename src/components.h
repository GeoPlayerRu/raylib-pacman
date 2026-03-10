class IComponent {
	public:
		virtual ~IComponent() {}
		virtual void process() = 0;
};

class Pacman : IComponent {
	public:
		virtual void process() {

		}
};
