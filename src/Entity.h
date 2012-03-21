#ifndef ENTITY_H
#define ENTITY_H


class Entity {

	public:
		Entity();
		~Entity();
		virtual void tick(double time);
		virtual void render(Screen* window, int id = -1);
		virtual int getID();
		bool setX(int xn);
		bool setY(int yn);

		int x;
		int y;
		int w;
		int h;
		double xSp;
		double ySp;
		Square* col;
		bool noRight;
		bool noLeft;
		bool noDown;
		bool noUp;
};


#endif
