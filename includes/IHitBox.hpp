#ifndef AHITBOX_HPP
#define AHITBOX_HPP

class AHitBox {
	public:
		virtual int getPosX(void) const = 0;
		virtual int getPosY(void) const = 0;
		virtual int getWidth(void) const = 0;
		virtual int getHeight(void) const = 0;

		bool collide(IHitBox const & obj) const;
};

#endif
