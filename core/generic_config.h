


template <typename T>
class generic_config
{
  public:
    static T& instance()
    {
        static T instance;
        return instance;
    }

    generic_config(T&&) = delete;
    generic_config(const T&) = delete;
    void operator=(const T&) = delete;

  protected:
    generic_config() = default;
    virtual ~generic_config() = default;
};




