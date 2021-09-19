
class ISplitter   // 抽象类
{
private:
    /* data */
public:
    virtual void split()=0;
    ISplitter(/* args */);
    ~ISplitter();
};

class BinarySplitter : public ISplitter // 具体类
{
private:
    /* data */
public:
    virtual void split(){}
    BinarySplitter(/* args */);
    ~BinarySplitter();
};


class TxtSplitter : public ISplitter    // 具体类
{
private:
    /* data */
public:
    virtual void split(){}
    TxtSplitter (/* args */);
    ~TxtSplitter ();
};

class PictureSplitter : public ISplitter  // 具体类
{
private:
    /* data */
public:
    virtual void split(){}
    PictureSplitter(/* args */);
    ~PictureSplitter();
};

class VideoSplitter : public ISplitter  // 具体类
{
private:
    /* data */
public:
    virtual void split(){}
    VideoSplitter(/* args */);
    ~VideoSplitter();
};




