class Horario < ApplicationRecord
  belongs_to :periodo
  belongs_to :curso
  has_one :asignacion
end
