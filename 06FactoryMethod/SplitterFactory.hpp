#include"Splitter.hpp"
// 工厂基类
class SplitterFactory
{
private:
    /* data */
public:

    virtual ISplitter* CreateSplitter() =0;
    virtual ~SplitterFactory(){}

};

class BinarySplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter* CreateSplitter()
    {
        return new BinarySplitter();
    }
};
class TxtSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter* CreateSplitter()
    {
        return new TxtSplitter();
    }
};

class PictureSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter* CreateSplitter()
    {
        return new PictureSplitter();
    }
};


class VideoSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter* CreateSplitter()
    {
        return new VideoSplitter();
    }
};
