# Структура хранения расписания
Программа должна брать данные с SQL таблицы и записывать в структуру для удобной дальнейшей работы.

Определить класс <Date> и переопределить операторы сравнения под него.
Определить структуру <Day>.
Определить класс <Timetable>. Timetable map <Date, Day>

# Day

Пользователю будет предложено добавить в свое дневное раписание событие с интервалом времен 15 мин.
Т.е. добавить "Обсуждение проекта" можно будет например в 19:15, 19:30, 19:45 и т.д. Таким образом
пользовательский день будет поделен на 24*4 = 96 частей.

# Поток мысли

    Не смотря на то, что количество ключей (0..94) заранее определено, нет смысла передавать
    и проверять те дела, которые не были добавлены. Зачем мне передавать bool (занят или нет), если
    можно передавать только когда занят.

    Можно создать множество временных интервалов на дню, которые хранят номер временного интервала.
    Например, ведем отсчет от 00:00. Хотя в какой-то степени это глупо, так как чаще всего в это время нормальный
    человек спит или готовится ко сну, но это второстепенный вопрос. В этом случае интервал
    от 00:00 до 00:15 считаем 0-вым, а 00:15 - 00:30 - 1-вым, тогда 23:45 - 00:00 - 94 
    (возникает вопрос с 24:00 и 00:00) 

    имеем set<int> freeTime, куда будем добавлять индексы свободных временных интервалов
    у всех участников группы. Это делается методом insert();
    erase() - метод удаления из множества.
    count() - посчитать количество вхождений элемента в множество.

    Элементы множетсва хранятся в отсортированном порядке и уникальны.

    Теперь я могу создать множества с занятыми или свободными временными частями и сравнивать их.

    Получается что количество свободных или занятых индексов у человека <= 94. Условимся, что примерно треть 
    временных частей у каждого свободна, что примерно равно 8-часам. Какой-то ооочень свободный человек, наверное
    он в отпуске.  Пусть это будет часов 5. Какое количество людей может быть в группе, 
    чтобы можно было их всех собрать? Кажется, что даже собрать 30 - 40 человек на какое-то продолжительное 
    мероприятие уж очень сложно при условии, что присутствуют все и на всем временном интервале
    мероприятия. Если приграмма предложит собраться 30 человечкам на 15 минут где-то в центре, 
    то вероятно половина просто не поедет ради 15 минут, другая отложит дела, чтобы хотя бы переброситься парой
    слов, а не просто поздороваться.

    Предлагаю ввести процент для временного индекса, который отражает процент "свободности" группы в 
    этот интервал времени. Т.е. если в это время свободны только 0.4 от всей группы - считаем, что
    это время у всех занято. При этом если например, у 25 из 27 свободно, то свободным (как говорится, 
    семеро одного не ждут).

    Но даже в этом случае, разве имеет значение встреча, если она длится 15 или 30 минут. Наверное,
    для кого-то она и имеет значение, но если так важно встретиться именно в этот день и на 15 минут ,
    то не проще ли человеку самостоятельно отложить какие-то дела и встретиться с кем-то в срочном порядке?

    Наверное имеет смысл ввести коэффициент, который будет зависить от n (количества участников в группе),
    и будет определять минмальное время, которое мы считаем достаточным для встречи, которую будет нестыдно
    предложить пользователю.

    Ну например, если 4 человеяка решили посидеть в калике или обсудить проект по ТП, наверное свободные 2 часа (с учетом дороги) 
    у всех уже нужно считать отличным вариантом. 
    А если таких людей, например 20? Пусть у кого-то годовщина, свадьба, др, концерт (ну я не знаю, что еще должно быть
    за событие, чтобы пришло столько занкомых людей). Обычно под такие массовые мероприятия выделяется чуть ли не весь день. Наверное будет
    глупо такому количеству людей предлагать в качестве варианта встречи 1 час. При этом надо отдавть себе отчет в том, что если мероприятие
    требует много овремени и люди это знают, то скорее всего они сами его и добавят в свой график. Но в целом кажется, понятно, 
    что при бОльшем n по идее и времени нужно больше, хотя бы из логики, что все, наверное, хотят пообщаться со всеми. 
    Этот момент надо обсудить, но то что 15 минут свободного времени для встрчи недостаточно, думаю, логично.

    Поэтому есть предложение определить функцию минимального времени встречи от параметров "посещаемости" и количества участников.
    t = F(k,n), где 
    t - минмальное время встречи, которое считаем подходящим для преложения
    k - процент тех кто свободен в это время (тут дальше можно думать о предложении человеку поменять график (mvp+))
    n - количество участников.

    Функцию подберем имперически (надо будет посмотреть, мб подобные идеи где-то реализованы).

    После того как мы сможем подобрать варант свободного времени (он хранится в каком-то виде), мы бросаемм его в эту функцию, которая вернет
    тру, если этот вариант адекватный. После чего кидаем его пользователям.

    Дальнейший вариант рассуждений - это придумать струткуру и алгоритм для 4 человек. Принять k = 0.7 (т.е. если могут 3 из 4,
    то встреча организовывается) Для n = 3 принимаем tmin = 45 минут. n = 4 => tmin 60 минут.
    такие параметры кажется логичными, а если вы с ними не слогасны, то скажу что это сугубо для 
    проверки алгоритма;)


# Event
struct <Event> {
    int Start;
    int Size;
    char* Name;
    ... // Можно добавить других поля хранящие данные указанные пользователем (место, описание и т.д.)
}
.Start - хранит номер части с которой начинается событие
.Size - хранит количество частей, которые занимает событие (1 часть - 15 минут, 4 части - 1 час)

# Связи группа-человек-событие
struct Group { 
    int id;
    
}