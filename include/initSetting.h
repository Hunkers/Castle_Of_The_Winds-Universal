#ifndef INITSETTING_H
#define INITSETTING_H

class Init {
	private:
		int windowX, windowY;
		
	public:
		/**Constructors**/
		Init();
		
		/**Acessors & Mutators**/
		//Set X & Y dimensions for window.
		void setWinX(int x); void setWinY(int y); 
		//Get X & Y dimensions for window.
		int getWinX(); int getWinY();
};

#endif //INITSETTING_H INCLUDED
