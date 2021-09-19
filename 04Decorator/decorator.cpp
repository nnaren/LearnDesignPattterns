//  "单一职责"模式  装饰
class Stream
{
private:
    /* data */
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;
    virtual ~Stream() {}
};

class FileStream : public Stream
{
private:
    /* data */
public:
    virtual char Read(int number) {}
    virtual void Seek(int position) {}
    virtual void Write(char data) {}

  
};

class MemoryStream : public Stream
{
private:
    /* data */
public:
    virtual char Read(int number) {}
    virtual void Seek(int position) {}
    virtual void Write(char data) {}

  
};

class NetworkStream : public Stream
{
private:
    /* data */
public:
    virtual char Read(int number) {}
    virtual void Seek(int position) {}
    virtual void Write(char data) {}
};

class DecoratorStream : public Stream {
protected:
    Stream* stream_; // = new FileStream();
    DecoratorStream(Stream* stream) : stream_(stream) {}
    DecoratorStream();
};


class CryptoStream  : public DecoratorStream
{
    
public:
    CryptoStream(Stream * stream) : DecoratorStream(stream) {}
    virtual char Read(int number) {
        stream_->Read(number);
    }
    virtual void Seek(int position) {
        stream_->Seek(position);
    }
    virtual void Write(char data) {
        stream_->Write(data);
    }

};

class BufferedStream : public DecoratorStream
{
private:
    Stream* stream_; // = new FileStream();
public:
    BufferedStream(Stream * stream) : DecoratorStream(stream) {}
    BufferedStream(/* args */) {}
    virtual char Read(int number) {
        stream_->Read(number);
    }
    virtual void Seek(int position) {
        stream_->Seek(position);
    }
    virtual void Write(char data) {
        stream_->Write(data);
    }
};

void Process() {
    // 运行时装配
    FileStream* s1 = new FileStream();
    CryptoStream* s2 = new CryptoStream(s1);
    BufferedStream* s3 = new BufferedStream(s2);
}