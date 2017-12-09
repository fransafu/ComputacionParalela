class Facultad < ApplicationRecord
  self.table_name='facultades'
  has_many :departamentos
end
