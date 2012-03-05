#ifndef ENTITY_H
#define ENTITY_H


class Entity {

	public:
		Entity();
		~Entity();
		virtual void tick(double time);
		virtual void render(Screen* window);
		virtual int getID();

	protected:
		int x;
		int y;
		double xSp;
		double ySp;

};


#endif
