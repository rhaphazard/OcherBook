#ifndef MX50_FB_H
#define MX50_FB_H

#include <linux/mxcfb.h>

#include "ocher/ux/fb/FrameBuffer.h"

class Mx50Fb : public FrameBuffer
{
public:
    Mx50Fb();
    ~Mx50Fb();

    bool init();

    unsigned int height();
    unsigned int width();
    unsigned int dpi() { return 170; }  // Kobo Touch -- measure it yourself!

    void setFg(uint8_t r, uint8_t b, uint8_t g);
    void setBg(uint8_t r, uint8_t b, uint8_t g);
    void clear();
    void pset(int x, int y);
    void hline(int x1, int y, int x2);
    inline void vline(int x, int y1, int y2) { line(x, y1, x, y2); }
    void blit(unsigned char *p, int x, int y, int w, int h);
    void fillRect(Rect* r);
    int update(Rect* r, bool full);

    /**
     * @param marker  Waits on the specified update, or -1 for all
     */
    void waitUpdate(int marker = -1);

    void setPixelFormat();
    void setUpdateScheme();
    void setAutoUpdateMode(bool autoUpdate);

protected:
    int m_fd;
    char *m_fb;
    size_t m_fbSize;
    int m_marker;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    unsigned int m_clears;
    uint8_t m_fgColor;
    uint8_t m_bgColor;
};

#endif

