#ifndef WIDPAINTER
#define	WIDPAINTER

#include <string.h>
#include <stdint.h>

namespace dr {
    
    class wid;
    
    class wid_painter {
    public:
        wid_painter(wid* wid_);
        virtual ~wid_painter();
        wid* m_wid;
        virtual int drawv(float x_, float y_, float w_, float h_)=0;
    protected:
        
    private:
        wid_painter(const wid_painter&);
        wid_painter& operator=(const wid_painter&);
    };


}



#endif	/* WIDPAINTER */

