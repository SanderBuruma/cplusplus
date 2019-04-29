#ifndef MOTHER_H
#define MOTHER_H


class Mother
{
    public:
        int publicv;
        Mother();
        ~Mother();
        void sayName();

    protected:
        int protectedv;

    private:
        int privatev;
};

#endif // MOTHER_H
