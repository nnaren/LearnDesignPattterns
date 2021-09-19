#include<string>

class IProgress{
public:
    virtual void DoProgress(float value) = 0;
    virtual ~IProgress(){}
};

class FileSplitter // 目标subject
{
private:
    std::string filePath_;
    int fileNumber_;
    //ProgressBar* progressBar_; // 具体通知机制-控件
    IProgress* iProgress_;      // 抽象通知机制   抽象观察者
    // vetcor<IProgress*> iProgressList_;   // 抽象通知机制,支持多个观察者
public:
    FileSplitter(/* args */);
    ~FileSplitter();
    FileSplitter(const std::string& filePath, int fileNumber,
        IProgress* iProgress) :
    filePath_(filePath),
    fileNumber_(fileNumber),
    iProgress_(iProgress) {}

    void split(){
        // 1.读取大文件

        // 2.分批次向小文件中写入
        for (int i = 0; i < fileNumber_; i++){
            //...
            float progressValue = fileNumber_;
            progressValue = (i+1) / progressValue;
            onProgress(progressValue);  // 更新进度条
        }
        
    }
/*
void addIProgress(IProgress* iprogress){    // 订阅通知
    iProgressList_.add(iprogress);
}
    
void removeIProgress(IProgress* iprogress){  // 取消订阅通知
    iProgressList_.remove(iprogress);
}

*/
protected:
    virtual void onProgress(float value){   // 抽象通知
        if(iProgress_ != nullptr){
            iProgress_->DoProgress(value); //更新进度条
        }
        
    }
};
