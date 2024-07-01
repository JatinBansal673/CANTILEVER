#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Product
{
    public:
    int id,quantity;
    string name;
    string category;
    double price;

    Product(int id,string name,string cat,double price,int quantity)
    {
        this->id=id;
        this->name=name;
        this->category=cat;
        this->price=price;
        this->quantity=quantity;
    }

    int get_id()
    {
        return id;
    }
    void set_id(int id)
    {
        this->id=id;
    }

    string get_name()
    {
        return name;
    }
    void set_name(string name)
    {
        this->name=name;
    }

    string get_category()
    {
        return category;
    }
    void set_category(string category)
    {
        this->category=category;
    }

    int get_price()
    {
        return price;
    } 
    void set_price(double price)
    {
        this->price=price;
    }

    int get_quantity()
    {
        return quantity;
    }
    void set_quantity(int quantity)
    {
        this->quantity=quantity;
    }
};

class Inventory
{
    vector<Product> products;
    public:
    void addproduct(Product product)
    {
        bool found=false;
        for(auto& p : products)
        {
             if(p.get_id()==product.get_id())
             {
                cout<<"Id already exist."<<endl;
                found=true;
                break;
             }
        }
        if(!found)
        {
            products.push_back(product);
            cout<<"Product added successfully"<<endl;
        }
    } 
    void removeproduct(int id)
    {
        bool found=false;
        for(auto p=products.begin(); p!=products.end(); p++)
        {
             if(p->get_id()==id)
             {
                products.erase(p);
                cout<<"Product removed successfully."<<endl;
                found=true;
                break;
             }
        }
        if(!found)
        {
            cout<<"Product Id does not exist."<<endl;
        }
    }
    Product* findproduct(int id)
    {
        for(auto p=products.begin(); p!=products.end(); p++)
        {
            if(p->get_id()==id)
            {
                return &(*p);
            }
        }
        return nullptr;
    }   
    void updateproduct(int id,string name,string category,double price,int quantity)
    {
        bool found=false;
        for(auto p=products.begin(); p!=products.end(); p++)
        {
            if(p->get_id()==id)
            {
                p->set_name(name);
                p->set_category(category);
                p->set_price(price);
                p->set_quantity(quantity);
                cout<<"Product Updated Successfully."<<endl;
                found=true;
                break;
            }
        }
        if(!found)
        {
            cout<<"Product Id does not exist."<<endl;
        }
    
    }
    void get_product_info()
    {
        for(auto p=products.begin(); p!=products.end(); p++)
        {
            cout<<"Product ID: "<<p->get_id()<<endl;
            cout<<"Product Name: "<<p->get_name()<<endl;
            cout<<"Product Category: "<<p->get_category()<<endl;
            cout<<"Product Price: "<<p->get_price()<<endl;
            cout<<"Product Quantity: "<<p->get_quantity()<<endl;
            cout<<endl;
        }
    }
    void save_to_file(string filename)
    {
        ofstream file;
        file.open(filename,ios::app | ios::out);
        for(int i=0;i<products.size();i++)
        {
            Product p=products[i];
            file<<p.get_id()<<","<<p.get_name()<<","<<p.get_category()<<","<<p.get_price()<<","<<p.get_quantity()<<endl;
        }
        file.close();
    }
    void display_inventory(string filename)
    {
        ifstream file;
        char ch;
        file.open(filename);
        if(file.is_open())
        {
            while(1)
            {
                if(file.eof()!=0)
                {
                    break;
                }
                ch=file.get();
                cout<<ch;
            }
        file.close();
        }
        else
        {
            cout<<"File not found"<<endl;
        }
    }
};

int main()
{
    Inventory invent;
    int i;
    char ch;
    do
    {
        cout<<"Inventory Management System"<<endl;
        cout<<"Please choose an option:"<<endl;
        cout<<"1. Add a Product"<<endl;
        cout<<"2. Remove a Product"<<endl;
        cout<<"3. Find a Product"<<endl;
        cout<<"4. Update a Product"<<endl;
        cout<<"5. Display all Product"<<endl;
        cout<<"6. Save Product Info to file"<<endl;
        cout<<"7. Display Inventory from file"<<endl;
        cout<<"8. Exit"<<endl;
        cin>>i;
       
        switch(i)
        {
            case 1:
            {
                int id,quantity;
                double price;
                string name,category;
                cout<<"Enter Id: ";
                cin>>id;
                cout<<"Enter Product name: ";
                cin>>name;
                cout<<"Enter Category: ";
                cin>>category;
                cout<<"Enter Product Price: ";
                cin>>price;
                cout<<"Enter Product Quantity: ";
                cin>>quantity;
                Product product(id,name,category,price,quantity);
                invent.addproduct(product);
                break;
            }
            case 2:
            {
                int id;
                cout<<"Enter Product Id to remove: ";
                cin>>id;
                invent.removeproduct(id);
                break;
            }
            case 3:
            {
                Product *p;
                int id;
                cout<<"Enter Product Id to find: ";
                cin>>id;
                p=invent.findproduct(id);
                if(p)
                {
                    cout<<"Product Name: "<<p->get_name()<<endl;
                    cout<<"Product Category: "<<p->get_category()<<endl;
                    cout<<"Product Price: "<<p->get_price()<<endl;
                    cout<<"Product Quantity: "<<p->get_quantity()<<endl;
                }
                else
                {
                    cout<<"Product not found."<<endl;
                }
                break;
            }
            case 4:
            {
                int id,quantity;
                double price;
                string name,category;
                cout<<"Enter Id: ";
                cin>>id;
                cout<<"Enter Product name: ";
                cin>>name;
                cout<<"Enter Category: ";
                cin>>category;
                cout<<"Enter Product Price: ";
                cin>>price;
                cout<<"Enter Product Quantity: ";
                cin>>quantity;
                invent.updateproduct(id,name,category,price,quantity);
                break;
            }
            case 5:
            {
                invent.get_product_info();
                break;
            }
            case 6:
            {
                invent.save_to_file("inventory.txt");
                cout<<"Inventory saved successfully."<<endl;
                break;
            }
            case 7:
            {
                invent.display_inventory("inventory.txt");
                break;
            }
            case 8:
            {
                cout<<"Application closed successfully."<<endl;
                break;
            }
            default:
            {
                cout<<"Invalid Input."<<endl;
            }
        }
    }while(i!=8);
    return 0;
}